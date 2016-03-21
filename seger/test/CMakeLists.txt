# file(GLOB SEGER_UTILS_UNITTEST_SOURCES *.cpp)
set(SEGER_LIB_UNITTEST_SOURCES
        test_utf8_io.cpp
        test_str_op.cpp
        initialize_easyloggingpp.cpp
        test_score_ret.cpp
        test_emws_seger.cpp
        )

# find_package(GTest REQUIRED)
set(GTEST_INCLUDE_DIRS ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(GTEST_BOTH_LIBRARIES gtest gtest_main)
message(STATUS ${GTEST_INCLUDE_DIRS})
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(seger_lib_unittest ${SEGER_LIB_UNITTEST_SOURCES})

target_link_libraries(seger_lib_unittest ${GTEST_BOTH_LIBRARIES})
message(STATUS ${SEGER_LIB_NAME})

# find_library(SEGER_UTILS_LIB ${SEGER_UTILS} ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
target_link_libraries(seger_lib_unittest ${SEGER_LIB_NAME})

add_test(NAME AllTestsInSegerLib
        COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/seger_lib_unittest
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/)

# use Catch
message(STATUS ${CATCH_INCLUDE_DIR})
include_directories(${CATCH_INCLUDE_DIR})
add_executable(test_catch_func ./test_catch_func.cpp)

add_test(NAME test_catch_func
        COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test_catch_func
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/)

# public includes
set(${PROJECT_NAME}_INCLUDE_DIRS ${${PROJECT_NAME}_INCLUDE_DIRS}
        ${GTEST_INCLUDE_DIRS}
        ${CATCH_INCLUDE_DIR}
        CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
