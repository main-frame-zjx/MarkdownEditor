cmake_minimum_required(VERSION 3.5) # cmake .. -G "Unix Makefiles"
project(MARKDOWNEDITOR)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src/public")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src/public/Commands")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src/public/MarkDownFile")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src/public/Utils")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src/public/logging")

AUX_SOURCE_DIRECTORY("${CMAKE_CURRENT_SOURCE_DIR}/src/private" DIR_SRCS)
AUX_SOURCE_DIRECTORY("${CMAKE_CURRENT_SOURCE_DIR}/src/private/Commands" DIR_SRCS)
AUX_SOURCE_DIRECTORY("${CMAKE_CURRENT_SOURCE_DIR}/src/private/MarkDownFile" DIR_SRCS)
AUX_SOURCE_DIRECTORY("${CMAKE_CURRENT_SOURCE_DIR}/src/private/Utils" DIR_SRCS)
AUX_SOURCE_DIRECTORY("${CMAKE_CURRENT_SOURCE_DIR}/src/private/logging" DIR_SRCS)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(MarkDownEditor ./src/main.cpp ${DIR_SRCS})

# target_link_libraries(MarkDownEditor stdc++fs)
add_subdirectory(test)