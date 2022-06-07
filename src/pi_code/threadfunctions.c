//#include <iostream>
//#include <cstdlib>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <wiringSerial.h>
#include "structures.h"
#include "functions.h"
#include "threadfunctions.h"

//From threadfunctions.h
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

//From threadfunctions.h
void *reading(void* mem_ptr) {
    MemoryStructure *mem_ptr_ = mem_ptr;
	
    int fd;
	
    // Check if serial port is open
    if ((fd = serialOpen("/dev/ttyS0", 115200)) < 0) {
        fprintf(stderr, "Unable to open serial device: %s\n", strerror(errno));
    }

    // Loop to parce serial data for struct
    for(;;){
        // create buffer to store line
        char buff[100];

        // Read serial data into buffer
        //read(fd, buff, 100);

        // Build a string with incoming characters, stopping only if found end of JSON,
        // or if to many charachters for the string.
        int t = 0;// Caracter index
        bool validdata = false; // Whether the JSON start char has found 
        buff[0] = 'x'; // Default first character of buffer
        while(buff[t] != '}' && t < 66) {
            // Store character in current position
            buff[t] = putchar(serialGetchar(fd));
            //Only increment position if the start of a valid JSON is found,
            // or if it has been previously found
            if(validdata || buff[t] == '{'){
                validdata = true;
                    t++;
            }
        }

	    //printf("%s", buff);

        // Parse the JSON string for tags, and save the data
        double range;
        bool range_on, camera_on;
        int j, k;

        for(int i=0; i<sizeof(buff); i++){
            if(buff[i]=='e' & buff[i+1]=='_' & buff[i+8]=='t'){
                //printf("%s\n", "range_on is true");
                range_on = 1;
                j = i-9;
            }else if(buff[i]=='e' & buff[i+1]=='_' & buff[i+8]=='f'){
                //printf("%s\n", "range_on is false");
                range_on = 0;
                j = i-9;
            }
            
            if(buff[i]=='a' & buff[i+1]=='_' & buff[i+8]=='t'){
                //printf("%s\n", "camera_on is true");
                camera_on = 1;
            }else if(buff[i]=='a' & buff[i+1]=='_' & buff[i+8]=='f'){
                //printf("%s\n", "camera_on is false");
                camera_on = 0;
            }
            
            if(buff[i]=='e' & buff[i+2]==' ' & buff[i+3]==':'){
                k = i+5;
            }
        }
        
        char rangeString[j-k+1];
        for(int n=0; n<sizeof(rangeString); n++){
            rangeString[n] = buff[k+n];
        }
        //printf("%s\n", rangeString);
        
        sscanf(rangeString, "%lf", &range);
        //printf("%lf\n", range);
        //printf("%d\n", range_on);
        //printf("%d\n", camera_on);

        // Save the data to memory
        mem_ptr_->controls_data.distance_on    = range_on;
        mem_ptr_->controls_data.recognition_on = camera_on;
        mem_ptr_->stm_data.distance = range;
    }
    // pthread_exit(NULL);
}

//From threadfunctions.h
void *audioOut(void* mem_ptr) {
    MemoryStructure *mem_ptr_ = mem_ptr;

    while(1){
       if(mem_ptr_->controls_data.distance_on){
            system("aplay -q /usr/local/lib/horus-res/sound/beep-01a.wav");
            delay(mem_ptr_->stm_data.distance);
       } else if(false){
            // Play sound recognition audio
       }
    }
    pthread_exit(NULL);
}
