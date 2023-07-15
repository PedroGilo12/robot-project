#!/bin/sh

cmake --build ../build/
echo "Project compiled, running...\n\n"

./../build/robot_project
