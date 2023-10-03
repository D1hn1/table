#!/bin/bash

if [[ $(ls build) != 0 ]]; then
	mkdir build
fi

g++ -o ./build/main ./src/main.cpp
