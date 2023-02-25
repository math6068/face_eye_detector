cmake_minimum_required(VERSION 3.0)

project(faces_detector)

# Find the Opencv and GTest lib
find_package(OpenCV REQUIRED)

# Add include directories
include_directories(include)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

include_directories(".")

# Set sources files
set(FACE_DETECTOR_SOURCES
    src/main.cpp
    src/FaceDetector.cpp
    src/EyesDetector.cpp
)

# Set header files
set(FACE_DETECTOR_HEADERS
    include/FaceDetector.hpp
    include/EyesDetector.hpp
)

# Set test files
set(TEST_SOURCES
    test/TestFaceDetector.cpp
)

# add_library(FaceDetector STATIC ${FACE_DETECTOR_SOURCES} ${FACE_DETECTOR_HEADERS})
add_executable(${PROJECT_NAME} ${FACE_DETECTOR_SOURCES} ${FACE_DETECTOR_HEADERS})
# target_include_directories(FaceDetector PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenCV_LIBS})


# # set up GTest
# enable_testing()
# add_executable(
#   TestFaceDetector
#   ${TEST_SOURCES}
# )
# target_link_libraries(
#   TestFaceDetector
#   GTest::gtest_main
# )
