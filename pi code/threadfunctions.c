//#include <iostream>
//#include <cstdlib>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include "structures.h"
#include "functions.h"
#include "threadfunctions.h"

//imageRec:
//Authers:
void *imageRec(void* mem_ptr) {
   //printf("Image Recognition works \n");
   pthread_exit(NULL);
}

//reading:
//Authers:
void *reading(void* mem_ptr) {
   //printf("Reading works \n");
   pthread_exit(NULL);
}

//toString:
//Authers:
void *toString(void* mem_ptr) {
   //printf("toString works \n");
   pthread_exit(NULL);
}

//concatenation:
//Authers:
void *concatenation(void* mem_ptr) {
   //printf("Concatenation works \n");
   pthread_exit(NULL);
}

//audioOut:
//Authers:
void *audioOut(void* mem_ptr) {
   system("aplay /usr/share/sounds/alsa/Front_Center.wav");
	printf("Audio Output works \n");
   pthread_exit(NULL);
}
