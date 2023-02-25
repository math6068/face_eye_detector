#include <opencv2/opencv.hpp>

class FaceDetector {
public:
    // Constructor that takes a path to a Haar cascade classifier file
    FaceDetector(std::string cascade_path);

    // Function that takes an input image and returns a vector of bounding boxes around detected faces
    std::vector<cv::Rect> face_detect(cv::Mat image);

private:
    // The Haar cascade classifier used for face detection
    cv::CascadeClassifier cascade_classier;
};
