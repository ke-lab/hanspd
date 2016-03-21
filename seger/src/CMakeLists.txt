project(seger-lib)

file(GLOB SEGER_LIB_SRCS *.cpp)
set(SEGER_LIB_NAME ${PROJECT_NAME} CACHE INTERNAL "seger-lib library name" FORCE)
set(SEGER_LIB_SRCS ${SEGER_LIB_SRCS} CACHE INTERNAL "seger-lib library source files" FORCE)

add_library(${SEGER_LIB_NAME} SHARED ${SEGER_LIB_SRCS})

target_link_libraries(${SEGER_LIB_NAME} ${ARMADILLO_LIBRARIES})