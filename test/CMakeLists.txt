cmake_minimum_required(VERSION 3.0) # cmake -G "MinGW Makefiles" ..
project(GTESTWIN_TEST)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

add_subdirectory(./googletest-release-1.8.1)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/googletest-release-1.8.1/googletest/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/googletest-release-1.8.1/googlemock/include)

include_directories("../src/public")
include_directories("../src/public/MarkDownFile")
AUX_SOURCE_DIRECTORY("../src/private" SRCS)
AUX_SOURCE_DIRECTORY("${CMAKE_CURRENT_SOURCE_DIR}" TEST_SRCS)

add_executable(MarkDownEditor_test ${DIR_SRCS} ${TEST_SRCS})

target_link_libraries(MarkDownEditor_test
        PRIVATE
        gtest
        gtest_main
        gmock
        gmock_main
        pthread)
