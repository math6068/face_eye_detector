FROM opencvcourses/opencv-docker:latest

ARG DEBIAN_FRONTEND=noninteractive

# Update and install packages
RUN apt-get update -y

RUN apt-get -y install g++ cmake

# Set the working directory
WORKDIR /
