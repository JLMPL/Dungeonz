#!/bin/sh

echo 'Out Copy'

cp -r CMakeFiles ..
rm -r CMakeFiles

cp -r CMakeCache.txt ..
rm -r CMakeCache.txt

cp -r cmake_install.cmake ..
rm -r cmake_install.cmake

cp -r Makefile ..
rm -r Makefile

cp -r run.sh ..
rm -r run.sh

cp -r count.sh ..
rm -r count.sh

cp -r Notes ..
rm -r Notes

cp -r Progression ..
rm -r Progression
