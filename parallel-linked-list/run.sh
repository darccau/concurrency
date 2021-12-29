#!/usr/bin/env bash

src_targe="parallel_linked_list.cpp"
cpp_flags="-Wall -pedantic -std=c++20"

g++ ${src_targe} ${cpp_flags} -o bin
./bin
