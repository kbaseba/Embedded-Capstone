# Embedded-Capstone
Repository for all code for UW EE475 Embedded Capstone project (Group 8) except Pi.img

horus-res includes resources called by the C program, it is currently missing libraries for object recognition, as they are too large, 
these libraries are included in the Pi.img. The path this folder is to be placed is "/usr/local/lib/"

physical design includes all files used for 3d printing the stm32s case.

src includes all source code

    pi_code includes all the C code running on the Pi, as well as a makefile that will compile to the correct path for the binary to run "usr/local/bin/"

    ml-utils includes python code for object detection. This is not used at runtime, it is used by scripts in resource folder.
    Contains machine learning models to detect and recognize objects. Requires python version 3.7

    stm_code includes the code that is to be compiled and loaded onto the STM32

Not included is Pi.img, that will be uploaded seperatly, it contains all of the settings, like the autorun service through systemd and the object librarys. 
It would be used to upload the code to any new raspberry pis if horus went into production.