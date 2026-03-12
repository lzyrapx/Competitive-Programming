#!/bin/bash

# sudo chmod +x run.sh

cppname=$1

outname="main"

g++ -std=c++11 -O3 $cppname -o $outname

./$outname