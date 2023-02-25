#include <opencv2/opencv.hpp>

class FaceDetector
{
public:
    FaceDetector(std::string cascade_path);
    std::vector<cv::Rect> face_detect(cv::Mat image);

private:
    cv::CascadeClassifier cascade_classier;
};
