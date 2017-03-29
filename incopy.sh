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

cp -r run.sh Rekt
rm -r run.sh

cp -r count.sh Rekt
rm -r count.sh

cp -r Notes Rekt
rm -r Notes
