#!/bin/sh

echo 'In Copy'

cd ..
cp -r CMakeFiles Rekt
rm -r CMakeFiles

cp -r CMakeCache.txt Rekt
rm -r CMakeCache.txt

cp -r cmake_install.cmake Rekt
rm -r cmake_install.cmake

cp -r Makefile Rekt
rm -r Makefile

