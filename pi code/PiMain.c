//#include <iostream>
//#include <cstdlib>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include "structures.h"
#include "functions.h"



//Main File
int main(int argc, char** argv) {

    struct MemoryStructure* mem_ptr = malloc(sizeof(struct MemoryStructure));


    runThreads(mem_ptr);

    free(mem_ptr);
    return 0;
}

void runThreads(MemoryStructure* mem_ptr){

    /*threadTasks[0] = imageRec;
    threadTasks[1] = reading;
    threadTasks[2] = toString;
    threadTasks[3] = concatenation;
    threadTasks[4] = audioOut;*/
    
    pthread_t thread_ids[NUM_THREADS];
    int i;
    for(i=0;i<NUM_THREADS;i++){
        //(*threadTasks[0])((void*)mem_ptr);
        pthread_create(&thread_ids[i], NULL, (*threadTasks[i]), (void*)mem_ptr);
    }

    for(i=0;i<NUM_THREADS;i++){
        pthread_join(thread_ids[i], NULL);
    }
}


void *imageRec(void* mem_ptr) {
   printf("Image Recognition works \n");
   pthread_exit(NULL);
}

void *reading(void* mem_ptr) {
   printf("Reading works \n");
   pthread_exit(NULL);
}

void *toString(void* mem_ptr) {
   printf("toString works \n");
   pthread_exit(NULL);
}

void *concatenation(void* mem_ptr) {
   printf("Concatenation works \n");
   pthread_exit(NULL);
}

void *audioOut(void* mem_ptr) {
   printf("Audio Output works \n");
   pthread_exit(NULL);
}
