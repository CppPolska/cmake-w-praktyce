#!/bin/bash

mkdir -p ./build
cd ./build
cmake ..
make tests
../bin/tests
if [[ $? -eq 0 ]]; then
	make all
fi