cmake_minimum_required(VERSION 3.3)
project(postagger)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_VERBOSE_MAKEFILE ON)

set(SOURCE_FILES  src/tagger/preprocessor/PreProcessor.cpp  src/tagger/crf/CRFTagger.cpp src/tagger/Base_Tagger.cpp  src/tagger/train.cpp src/tagger/preprocessor/strtool.cpp)

set(RapidJSON_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/third_party/rapidjson/include)
include_directories(${RapidJSON_INCLUDE_DIR})

set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/postagger/include
                                 ${RapidJSON_INCLUDE_DIR}
                                 CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

add_executable(train ${SOURCE_FILES})
target_link_libraries(train crfpp)
find_package(Boost REQUIRED COMPONENTS program_options)
if(Boost_FOUND)
    target_link_libraries(train_tagger ${Boost_LIBRARIES})
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(POS_FILES  src/tagger/preprocessor/PreProcessor.cpp  src/tagger/crf/CRFTagger.cpp src/tagger/Base_Tagger.cpp  src/tagger/preprocessor/strtool.cpp)
set(TAGGER_LIB_NAME ${PROJECT_NAME} CACHE INTERNAL "tagger-lib library name" FORCE)
add_library(${TAGGER_LIB_NAME} SHARED ${POS_FILES})
target_link_libraries(postagger crfpp)


