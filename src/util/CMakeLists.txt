generate_arduino_library(debug
        SRCS debug.h
        BOARD uno)

generate_arduino_library(RingBuffer
        SRCS RingBuffer.cpp
        HDRS RingBuffer.h
        BOARD uno)

generate_arduino_library(EspDrv
        SRCS EspDrv.cpp
        HDRS EspDrv.h
        BOARD uno)