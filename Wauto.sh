#!/bin/bash




cat /c/Users/user/workspace/OpenGL/RollsRoyce/RollsRoyce/RollsRoyce.cpp > vstudio.cpp
git diff > diff
cat diff
rm diff
git add vstudio.cpp
git commit -m "auto msg frm script"
git push
