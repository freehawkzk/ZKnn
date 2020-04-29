
FIND_PACKAGE( OpenMP REQUIRED)
if(OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

set(SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/checklicense.cpp
)

add_executable(checklicense ${SRC_FILES})
include_directories(/usr/local/include/opencv4 )
link_directories(/usr/local/lib)
target_link_libraries(checklicense PRIVATE EMPFaceBaseV5)
