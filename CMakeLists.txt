cmake_minimum_required(VERSION 3.15)

project(AdventOfCode2023)

set (CMAKE_CXX_STANDARD 23)

set (TOOLS tools/file_loader.hpp
        tools/timer.hpp
        tools/fstoi.hpp)


#set optimization flags for release
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")


set(TARGETS day1 day2 day3)

#create a build target for each day if the folder exists
foreach(I_TARGET ${TARGETS})
    if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${I_TARGET})
        add_executable(${I_TARGET} ${I_TARGET}/${I_TARGET}.cpp ${TOOLS})
    endif()
endforeach ()

foreach(I_TARGET ${TARGETS})
    if (TARGET ${I_TARGET})
        configure_file(${I_TARGET}/input.txt ${CMAKE_CURRENT_BINARY_DIR}/input.txt COPYONLY)
    endif()
endforeach()

