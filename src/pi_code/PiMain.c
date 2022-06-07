//#include <iostream>
//#include <cstdlib>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "structures.h"
#include "functions.h"
#include "threadfunctions.h"

int main(int argc, char** argv) {

    //init_py_env();

    struct MemoryStructure* mem_ptr = malloc(sizeof(struct MemoryStructure));

    runThreads(mem_ptr);

    free(mem_ptr);
    return 0;
}

//From functions.h, unused
void init_py_env(){
    system(". /usr/local/lib/horus-res/project/env/bin/activate && python --version");
}

//From functions.h
void runThreads(MemoryStructure* mem_ptr){

    //Array of function pointers to thread tasks, these are found in threadfunctions.h
    //  Make sure to update this list, NUM_THREADS, and the function header when adding a new thread
    //  They will run in parallel and use "pthread_exit(NULL)" to end a thread function before return
    void *(*threadTasks[NUM_THREADS])(void*) = {objectRec, reading, audioOut};  
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

//From functions.h. Sourced from https://c-for-dummies.com/blog/?p=69
void delay(int milliseconds)
{
	    long pause;
	        clock_t now,then;

		    pause = milliseconds*(CLOCKS_PER_SEC/1000);
		        now = then = clock();
			    while( (now-then) < pause )
				            now = clock();
}
