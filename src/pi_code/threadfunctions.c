//#include <iostream>
//#include <cstdlib>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <wiringSerial.h>
#include "structures.h"
#include "functions.h"
#include "threadfunctions.h"

//imageRec:
//Authers:
void *objectRec(void* mem_ptr) {
    //MemoryStructure *mem_ptr_ = mem_ptr;
    // Start recognition script
    system(". /usr/local/lib/horus-res/project/env/bin/activate && python /usr/local/lib/horus-res/project/Object_Detection_Picamera.py");
    //while
        //if control is off
            //end/halt process
        //else
            //start/resume

    //printf("Image Recognition Finished \n");
    pthread_exit(NULL);
}

//reading:
//Authers:
void *reading(void* mem_ptr) {
    MemoryStructure *mem_ptr_ = mem_ptr;

    int fd;

    // Check if serial port is open
    if ((fd = serialOpen("/dev/ttyS0", 115200)) < 0) {
        fprinf(stderr, "Unable to open serial device: %s\n", strerror(errno));
        return 1;
    }

    // Loop to parce serial data for struct
    for(;;){

        // create buffer to store line
        char buff[64];

        // Read serial data into buffer
        read(fd, buff, 8);

        // distance buffer
        char dist[10];

        // camera on buffer
        char range[10];

        // dist sensor on buffer
        char cam[10];

        for(int i = 0; i < 64; i++) {
            if (buff[i] == ":") {
                char dist[10];
                i = i + 2;

                int j = 0;
                while (buff[i] != " ") {
                    dist[j] = buff[i];
                    i++;
                    j++;
                }
                dist[i] = "\0";

                i = i + 16;

                int k = 0;
                while (buff[i] != " ") {
                    range[k] = buff[i];
                    i++;
                    k++;
                }
                range[k] = "\0";

                i = i + 17;

                int z = 0;
                while (buff[i] != " ") {
                    cam[z] = buff[i];
                    i++;
                    z++;
                }
                cam[z] = "\0";

                break;
            }
        }
        

        // For testing
        printf("%s", buff);
        printf("%s", dist);
        printf("%s", range);
        printf("%s", cam);
        printf("Reading Finished \n");
    }

    //Hardcoding data for testing
    mem_ptr_->controls_data.distance_on    = true;
    mem_ptr_->controls_data.recognition_on = false;
    int i = 0; // Run through some distances to test sound
    while(i <25){
       mem_ptr_->stm_data.distance = (double)i;
       delay(1000);
       i++;
    }

    // pthread_exit(NULL);
}


//audioOut:
//Authers: Cameron McCarty
void *audioOut(void* mem_ptr) {
    MemoryStructure *mem_ptr_ = mem_ptr;

    while(1){
       if(mem_ptr_->controls_data.distance_on){
            system("aplay -q /usr/local/lib/horus-res/sound/beep-01a.wav");
            delay(100 * mem_ptr_->stm_data.distance);
       } else if(mem_ptr_->controls_data.recognition_on){
            // Play sound recognition audio
       }
    }
    printf("Audio Output Finished \n");
    pthread_exit(NULL);
}
