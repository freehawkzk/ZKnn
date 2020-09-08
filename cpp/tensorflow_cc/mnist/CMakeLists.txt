

set(SRC_FILES
${CMAKE_CURRENT_SOURCE_DIR}/mnist.cpp
)

add_executable(tensorflow_mnist_cpp ${SRC_FILES})
include_directories(/usr/local/include/opencv4 /usr/local/include/tf)
link_directories(/usr/local/lib)
target_link_libraries(tensorflow_mnist_cpp PRIVATE MNN opencv_core opencv_highgui opencv_imgcodecs opencv_imgproc opencv_dnn)
