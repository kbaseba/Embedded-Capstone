#pragma once

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

    typedef struct StmData{
        int data;
    }StmData;

    typedef struct ControlsData{
        int data;
    }ControlsData;

    typedef struct ImageRecData{
        int data;
    }ImageRecData;

    typedef struct MemoryStructure{
        StmData      stm_data;
        ControlsData controls_data;
        ImageRecData image_rec_data;
    }MemoryStructure;

#endif