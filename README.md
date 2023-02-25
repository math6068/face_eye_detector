# Face Detection using OpenCV C++
This is a C++ project that uses the OpenCV library to detect faces in an image.

# Dependencies
* C++14 or higher
* OpenCV 4.5.4 or higher

# Using with Visual Studio Code Remote Containers
If you have Visual Studio Code and Docker installed, you can use the devcontainer configuration in this repository to develop and run the code inside a Docker container. This allows for consistent and reproducible development environments.

Clone the repository and open the folder in Visual Studio Code.
When prompted to open the folder in a container, select "Reopen in Container".
Visual Studio Code will build the Docker container and launch it in a new window.
Open a terminal in the new window and navigate to the `/workspaces/face_eyes_detector` directory.

## Using CMake inside the dev container 
CMake is an open-source, cross-platform build system that helps you manage the build process of a C++ project. Steps to build and run this project:
`cmake -S . -B build `
`cmake --build build `
`./build/faces_detector {path_to_input_image} {path_to_output_image}`

# License
This project is licensed under the MIT License - see the LICENSE file for details.