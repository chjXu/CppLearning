#/bin/bash

#make
gcc ./example/example.cpp -v  -o example1 -I ./include -pthread -std=c++11 -lstdc++

#run

./example1