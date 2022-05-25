//#include <iostream>
//#include <cstdlib>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "structures.h"
#include "functions.h"
#include "threadfunctions.h"

//imageRec:
//Authers:
void *objectRec(void* mem_ptr) {
    MemoryStructure *mem_ptr_ = mem_ptr;
    // Start recognition script
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

    //Hardcoding data for testing
    mem_ptr_->controls_data.distance_on    = true;
    mem_ptr_->controls_data.recognition_on = false;
    int i = 0; // Run through some distances to test sound
    while(i <25){
       mem_ptr_->stm_data.distance = (double)i;
       delay(1000);
       i++;
    }

    printf("Reading Finished \n");
    pthread_exit(NULL);
}

//toString:
//Authers:
void *toString(void* mem_ptr) {
    MemoryStructure *mem_ptr_ = mem_ptr;
    //printf("toString Finished \n");
    pthread_exit(NULL);
}

//concatenation:
//Authers:
void *concatenation(void* mem_ptr) {
    MemoryStructure *mem_ptr_ = mem_ptr;
    //printf("Concatenation Finished \n");
    pthread_exit(NULL);
}

//audioOut:
//Authers: Cameron McCarty
void *audioOut(void* mem_ptr) {
    MemoryStructure *mem_ptr_ = mem_ptr;

    int i = 0; // Used to auto stop execution
    while(i <250){
       if(mem_ptr_->controls_data.distance_on){
            system("aplay -q /usr/local/bin/horus-res/beep-01a.wav");
            delay(100 * mem_ptr_->stm_data.distance);
       } else if(mem_ptr_->controls_data.recognition_on){
            // Play sound recognition audio
       }
    }
    printf("Audio Output Finished \n");
    pthread_exit(NULL);
}
