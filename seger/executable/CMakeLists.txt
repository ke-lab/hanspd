project(seger-exec)


set(TRAIN_SRCS emws-train.cpp)
set(PREDICT_SRCS emws-predict.cpp)

set(TRAIN_EXEC emws-train)
set(PREDICT_EXEC emws-predict)


add_executable(${TRAIN_EXEC} ${TRAIN_SRCS} ${SEGER_SRCS})
add_executable(${PREDICT_EXEC} ${PREDICT_SRCS} ${SEGER_SRCS})

# boost program_options
find_package(Boost REQUIRED COMPONENTS program_options)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${TRAIN_EXEC} ${Boost_LIBRARIES})
    target_link_libraries(${PREDICT_EXEC} ${Boost_LIBRARIES})
endif()

target_link_libraries(${TRAIN_EXEC} ${SEGER_LIB_NAME})
target_link_libraries(${PREDICT_EXEC} ${SEGER_LIB_NAME})