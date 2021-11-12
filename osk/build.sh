#!/usr/bin/env bash

# build the program
printf "Building application...\n"
makeResult=$(pspdev-docker make)

if [ "$makeResult" -gt 0 ]; then
  printf "Make returned code %d, aborting." makeResult
fi

# delete redundant files
printf "Removing *.o files: %s\n" "$(find . -type f -name "*.o")"
find . -type f -name '*.o' -delete

printf "Removing *.elf files: %s\n" "$(find . -type f -name "*.elf")"
find . -type f -name '*.elf' -delete

# create the build directory if it doesn't exist
printf "Checking if %s/build/ directory exists...\n" "$(pwd)"
if [ ! -d "build" ]; then
  printf "Creating %s/build/ directory...\n" "$(pwd)"
  mkdir build
fi

# move the executables to the build directory
printf "Moving %s and %s files to build/ directory...\n" "$(find . -maxdepth 1 -type f -name "*.PBP")" "$(find . -maxdepth 1 -type f -name "*.SFO")"
mv -f ./*.PBP build/
mv -f ./*.SFO build/
printf "Done!\n"