#include "FaceDetector.hpp"

FaceDetector::FaceDetector(const std::string& cascade_filepath)
{
    cascade_classier.load(cascade_filepath);
}

void FaceDetector::face_detect(const cv::Mat& input_image, std::vector<cv::Rect>& faces)
{
    cascade_classier.detectMultiScale(input_image, faces);
}
