#include <opencv2/opencv.hpp>

class EyeDetector {
public:
    // Constructor that takes a path to a Haar cascade classifier file
    EyeDetector(std::string cascade_path);

    // Function that takes an input image and returns a vector of bounding boxes around detected eyes
    std::vector<cv::Rect> eyes_detect(cv::Mat image);

private:
    // The Haar cascade classifier used for eye detection
    cv::CascadeClassifier cascade_classier;
};
