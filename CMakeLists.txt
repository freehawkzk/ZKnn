cmake_minimum_required(VERSION 2.8.12)

project(zknn-cpp)
set(CMAKE_BUILD_TYPE Release )
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)
add_subdirectory(./cpp/linearmodel)
add_subdirectory(./cpp/nonlinearmodel)
# add_subdirectory(./cpp/getmachinecode)
# add_subdirectory(./cpp/createlicensecode)
# add_subdirectory(./cpp/checklicense)
add_subdirectory(./cpp/mnist-cnn)

