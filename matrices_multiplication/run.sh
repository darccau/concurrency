#!/usr/bin/bash

serial_src='serial.cpp'
parallel_src='parallel.cpp'
compile_flags='-std=c++11 -Wall -pedantic -lpthread'

g++ ${serial_src} -o parallel ${compile_flags}
./parallel
