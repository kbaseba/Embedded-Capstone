#pragma once

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

    typedef struct StmData{
        int data;
    }StmData;

    typedef struct ControlsData{
        bool distance_on;
        bool recognition_on;
    }ControlsData;

    typedef struct ImageRecData{
        int data;
    }ImageRecData;

    typedef struct MemoryStructure{
        StmData      *stm_data;
        ControlsData *controls_data;
        ImageRecData *image_rec_data;
    }MemoryStructure;

#endif