#include "../include/EyesDetector.hpp"

EyeDetector::EyeDetector(std::string cascade_path) {
    if (!cascade_classier.load(cascade_path)) {
        throw std::runtime_error("Failed to load cascade file");
    }
}

std::vector<cv::Rect> EyeDetector::eyes_detect(cv::Mat img) {
    std::vector<cv::Rect> eyes;

    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(gray, gray);

    cascade_classier.detectMultiScale(gray, eyes, 1.1, 3, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

    return eyes;
}