#!/bin/sh

cmake --build ../build/
echo "Project compiled, running...\n\n"

sudo ./../build/robot_project
