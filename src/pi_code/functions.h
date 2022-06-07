/*
    Functions.h contains forword declarations and explanations of gebneral functions used
    Authors: Cameron McCarty
*/
#pragma once

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#define PATH_TO_INIT_SCRIPT ./

    //init_py_env: Runs the script to setup the correct python enviroment, no longer used, now the script is called by the objectRec thread
    //             It will also print out the python version to stdout, to confirm that it has worked.
    //Authers: Cameron McCarty
    // Uses a script made by Tilboon Elberier and Rahul Pulidindi
    void init_py_env();

    //runThreads: Dispatches each thread function given in *threadTasks[], and then ensures they are closed before exit.
    //Authers: Cameron McCarty, Zexuan Li
	void runThreads(MemoryStructure* mem_ptr);

    //Delay function, pauses the thread until a given time has passed
    //Authors: User dgookin from https://c-for-dummies.com/blog/?p=69, 
    void delay(int milliseconds);
#endif
