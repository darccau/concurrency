#!/usr/bin/env bash

src_target="src/*"
cpp_flags="-Wall -pedantic -std=c++11 -l pthread"

g++ ${src_target} ${cpp_flags} -o bin
./bin
rm bin
