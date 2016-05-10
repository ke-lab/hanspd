cmake_minimum_required(VERSION 3.3)
project(hanspd)

# output dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DPERCEPTRON_FOR_DECODING -DLABELED -DTARGET_LANGUAGE=chinese")
# set (CMAKE_CXX_FLAGS "-std=c++11 -g -w -W -O3 -DNDEBUG -DPERCEPTRON_FOR_DECODING -DLABELED -DTARGET_LANGUAGE=chinese")


# openmp
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

# You can tweak some common (for all subprojects) stuff here. For example:

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)

if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(SEND_ERROR "In-source builds are not allowed.")
endif ()

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE   ON)

# RapidJSON
# may need move rapidjson to top level dir
set(RapidJSON_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/seger/third_party/rapidjson/include)
include_directories(${RapidJSON_INCLUDE_DIR})

# sub project
add_subdirectory(seger)
add_subdirectory(postagger)
add_subdirectory(deparser)

message(STATUS ${han-seger_INCLUDE_DIRS})
message(STATUS ${SEGER_LIB_NAME})
message(STATUS ${SEGER_LIB_SRCS})

include_directories(${han-seger_INCLUDE_DIRS})
include_directories(${postagger_INCLUDE_DIRS})
include_directories(${deparser_INCLUDE_DIRS})

add_executable(hanspd-test test.cpp)

target_link_libraries(hanspd-test ${SEGER_LIB_NAME})
target_link_libraries(hanspd-test ${TAGGER_LIB_NAME})
target_link_libraries(hanspd-test ${DEPARSER_LIB_NAME})
