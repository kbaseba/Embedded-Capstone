//#include <iostream>
//#include <cstdlib>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include "structures.h"
#include "functions.h"
#include "threadfunctions.h"

//imageRec:
//Authers:
void *imageRec(void* mem_ptr) {
    //printf("Image Recognition Finished \n");
    pthread_exit(NULL);
}

//reading:
//Authers:
void *reading(void* mem_ptr) {
    //printf("Reading Finished \n");
    pthread_exit(NULL);
}

//toString:
//Authers:
void *toString(void* mem_ptr) {
    //printf("toString Finished \n");
    pthread_exit(NULL);
}

//concatenation:
//Authers:
void *concatenation(void* mem_ptr) {
    //printf("Concatenation Finished \n");
    pthread_exit(NULL);
}

//audioOut:
//Authers: Cameron McCarty
void *audioOut(void* mem_ptr) {
    int i = 0; // Used to auto stop execution
    while(i <25){
       if(mem_ptr->controls_data->distance_on){
            system("aplay BEEP_SOUND_FILE");
            delay(1000);
       } else if(mem_ptr->controls_data->recognition_on){
            // Play sound recognition audio
       }
    }
    printf("Audio Output Finished \n");
    pthread_exit(NULL);
}
