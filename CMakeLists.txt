cmake_minimum_required(VERSION 3.0)
project(robot_project C)

set(CMAKE_C_STANDARD 11)

include_directories(retrofit-omnino/include)

add_executable(robot_project 
	retrofit-omnino/main.c
        retrofit-omnino/include/motor_control_driver.h
        retrofit-omnino/src/motor_control_driver.c)
