/*
    structures.h contains data structures used to communicate data across threads.
    Authors: Cameron McCarty
*/
#pragma once

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

    //Data transimtted by stm sensors
    typedef struct StmData{
        double distance;
        double temperature;
    }StmData;

    //Data transmitted by stm control buttons
    typedef struct ControlsData{
        bool distance_on;
        bool recognition_on;
    }ControlsData;

    //Structure housing all data
    typedef struct MemoryStructure{
        StmData      stm_data;
        ControlsData controls_data;
    }MemoryStructure;

#endif