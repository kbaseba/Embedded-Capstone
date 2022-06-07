/*
    threadfunctions.h contains forword declarations and explanations of functions launched as seperate threads
    Authors: Cameron McCarty
*/
#pragma once
#ifndef THREADFUNCTIONS_H_
#define THREADFUNCTIONS_H_

// Defines the number of thread functions, increment this when adding more.
#define NUM_THREADS 3

//objectRec: Launches two scripts, the first sets up a python enviroment, 
//           the second launches object recognition in that enviroment
//Authers: Cameron McCarty
// Uses a scripts made by Tilboon Elberier and Rahul Pulidindi
void *objectRec(void* mem_ptr);

//reading: reads in data from serial port, parses it, and saves it to memory
//Authers: Cameron McCarty, Tilboon Elberier, Zexuan Li
void *reading(void* mem_ptr);

//audioOut: Plays a series of beeps, with the period based on the distance
//Authors: Cameron McCarty
// Uses a sound file found from https://www.soundjay.com/beep-sounds-1.html
void *audioOut(void* mem_ptr);

#endif