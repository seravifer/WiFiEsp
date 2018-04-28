generate_arduino_library(WiFiEsp
        SRCS  WiFiEsp.cpp
        HDRS  WiFiEsp.h
        BOARD uno)

generate_arduino_library(WiFiEspClient
        SRCS  WiFiEspClient.cpp
        HDRS  WiFiEspClient.h
        BOARD uno)

generate_arduino_library(WiFiEspServer
        SRCS  WiFiEspServer.cpp
        HDRS  WiFiEspServer.h
        BOARD uno)

generate_arduino_library(WiFiEspUdp
        SRCS  WiFiEspUdp.cpp
        HDRS  WiFiEspUdp.h
        BOARD uno)