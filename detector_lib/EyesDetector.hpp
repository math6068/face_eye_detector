#include <opencv2/opencv.hpp>

class EyeDetector {
public:
    EyeDetector(std::string cascade_path);
    std::vector<cv::Rect> eyes_detect(cv::Mat image);

private:
    cv::CascadeClassifier cascade_classier;
};
