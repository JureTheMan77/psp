#!/usr/bin/env bash

# build the program
make

# delete redundant files
find . -type f -name '*.o' -delete
find . -type f -name '*.elf' -delete

# create the build directory if it doesn't exist
if [ ! -d "build" ]; then
  mkdir build
fi

# move the executables to the build directory
mv ./*.PBP build/
mv ./*.SFO build/