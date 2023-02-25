#include "../include/FaceDetector.hpp"

FaceDetector::FaceDetector(std::string cascade_path) {
    // Load cascade classifier for face detection
    if (!cascade_classier.load(cascade_path)){
        throw std::runtime_error("Failed to load cascade file");
    }
}

std::vector<cv::Rect> FaceDetector::face_detect(cv::Mat image) {
    std::vector<cv::Rect> faces;
    cv::Mat grayImage;

    // Convert image to grayscale
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    // Detect faces using the loaded cascade classifier
    cascade_classier.detectMultiScale(grayImage, faces, 1.1, 2, 0|cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

    return faces;
}
