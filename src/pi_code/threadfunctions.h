#pragma once
#ifndef THREADFUNCTIONS_H_
#define THREADFUNCTIONS_H_

#define NUM_THREADS 5
// Sound file used for the distance beep, from https://www.soundjay.com/beep-sounds-1.html
//#define BEEP_SOUND_FILE "beep-01a.wav"

void *objectRec(void* mem_ptr);

void *reading(void* mem_ptr);

void *toString(void* mem_ptr);

void *concatenation(void* mem_ptr);

void *audioOut(void* mem_ptr);

//void *(*threadTasks[NUM_THREADS])(void*) = {imageRec, reading, toString, concatenation, audioOut};  

#endif