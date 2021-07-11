#!/bin/bash
clear
gcc src/*.c src/*/*.c -o bin/main
echo "C-c退出"
read
./bin/main


