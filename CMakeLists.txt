cmake_minimum_required(VERSION 3.0)
project(robot_project C)

set(CMAKE_C_STANDARD 11)

#find_library(WIRINGPI_LIBRARY wiringPi)

include_directories(retrofit-omnino/include)

add_executable(robot_project 
	retrofit-omnino/main.c
        retrofit-omnino/include/motor_control_driver.h
        retrofit-omnino/src/motor_control_driver.c retrofit-omnino/include/common.h)

#target_link_libraries(robot_project ${WIRINGPI_LIBRARY})
