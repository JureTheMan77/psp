#!/usr/bin/env bash

# build the program
printf "Building application...\n"
make

# delete redundant files
printf "Removing *.o files: %s\n" "$(find . -maxdepth 1 -type f -name "*.o")"
find . -type f -name '*.o' -delete

printf "Removing *.elf files: %s\n" "$(find . -maxdepth 1 -type f -name "*.elf")"
find . -type f -name '*.elf' -delete

# create the build directory if it doesn't exist
printf "Checking if %s/build/ directory exists...\n" "$(pwd)"
if [ ! -d "build" ]; then
  printf "Creating %s/build/ directory...\n" "$(pwd)"
  mkdir build
fi

# move the executables to the build directory
printf "Moving %s and %s files to build/ directory...\n" "$(find . -maxdepth 1 -type f -name "*.PBP")" "$(find . -maxdepth 1 -type f -name "*.SFO")"
mv ./*.PBP build/
mv ./*.SFO build/
printf "Done!\n"