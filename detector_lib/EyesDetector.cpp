#include <detector_lib/EyesDetector.hpp>

EyeDetector::EyeDetector(std::string cascade_path) {
    // Load the Haar cascade classifier from the specified file
    if (!cascade_classier.load(cascade_path)) {
        throw std::runtime_error("Failed to load cascade file");
    }
}

std::vector<cv::Rect> EyeDetector::eyes_detect(cv::Mat img) {
    std::vector<cv::Rect> eyes;

    // Convert the input image to grayscale
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    // Apply histogram equalization to improve contrast
    cv::equalizeHist(gray, gray);

    // Detect eyes using the Haar cascade classifier
    cascade_classier.detectMultiScale(gray, eyes, 1.1, 3, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

    // Return the bounding boxes of the detected eyes
    return eyes;
}
