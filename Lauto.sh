#!/bin/bash


g++ -lglut -lGL -lGLU Lmain.cpp -o object
./object
git add Lmain.cpp
git commit -m "automsg"
git push

