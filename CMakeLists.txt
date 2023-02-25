cmake_minimum_required(VERSION 3.0)

project(FaceDetector)

# Find the Opencv and GTest lib
find_package(OpenCV REQUIRED)
find_package(GTest REQUIRED)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)

# Set sources files
set(FACE_DETECTOR_SOURCES
    src/FaceDetector.cpp
)

# Set header files
set(FACE_DETECTOR_HEADERS
    include/FaceDetector.hpp
)

# Set test files
set(TEST_SOURCES
    test/TestFaceDetector.cpp
)

add_library(FaceDetector STATIC ${FACE_DETECTOR_SOURCES} ${FACE_DETECTOR_HEADERS})

target_include_directories(FaceDetector PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(FaceDetector PUBLIC ${OpenCV_LIBS})

# add_executable(TestFaceDetector ${TEST_SOURCES})
# Add executable target
add_executable(FaceDetector ${SOURCES})

target_include_directories(TestFaceDetector PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(TestFaceDetector PRIVATE FaceDetector ${GTEST_BOTH_LIBRARIES})

enable_testing()

add_test(NAME FaceDetectorTest COMMAND TestFaceDetector)
