#! /bin/bash

mkdir -p build

gcc -std=c17 -o build/program src/*.c -lraylib
