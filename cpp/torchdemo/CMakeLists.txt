cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(torchdemo)

set(CMAKE_PREFIX_PATH "/home/zk/src/ZKnn/cpp/libtorch/share/cmake/Torch")
find_package(Torch REQUIRED)

add_executable(torchdemo torchdemo.cpp)
target_link_libraries(torchdemo "${TORCH_LIBRARIES}")
set_property(TARGET torchdemo PROPERTY CXX_STANDARD 14)