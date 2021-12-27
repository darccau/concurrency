#!/usr/bin/bash

matrices_multiplication_src='matrices_multiplication.cpp'
compile_flags=' -Wall -pedantic -lpthread'

g++ ${matrices_multiplication_src} -o matrices_multiplication ${compile_flags}
./matrices_multiplication 4  C

# g++ sample.cpp -o sample ${compile_flags} -std=c++11 -pthread
# ./sample
