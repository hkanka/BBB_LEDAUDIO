cmake_minimum_required(VERSION 3.7)
project(beaglebone)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99")

set(SOURCE_FILES main.c BBBio_lib/BBBiolib.c font_5x7.h BBB_P10.c BBB_P10.h BBBio_lib/BBBiolib_PWMSS.c BBBio_lib/BBBiolib_ADCTSC.c BBBio_lib/BBBiolib_McSPI.c udp.h udp.c)
add_executable(beaglebone ${SOURCE_FILES})
SET (CMAKE_C_COMPILER /usr/bin/arm-linux-gnueabihf-gcc-4.7)
SET (CMAKE_CXX_COMPILER /usr/bin/arm-linux-gnueabihf-g++-4.7)
target_link_libraries(beaglebone pthread m)