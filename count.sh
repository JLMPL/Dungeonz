#!/bin/sh

echo 'Counting'

cloc src -exclude_dir=LuaBridge,rapidxml,base64
