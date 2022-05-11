//#include <iostream>
//#include <cstdlib>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include "structures.h"
#include "functions.h"
#include "threadfunctions.h"

int main(int argc, char** argv) {

    struct MemoryStructure* mem_ptr = malloc(sizeof(struct MemoryStructure));

    runThreads(mem_ptr);

    free(mem_ptr);
    return 0;
}

//runThreads: Dispatches each thread function given in *threadTasks[]
//Authers: Cameron McCarty, Zexuan Li
void runThreads(MemoryStructure* mem_ptr){

   void *(*threadTasks[NUM_THREADS])(void*) = {imageRec, reading, toString, concatenation, audioOut};   
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

