#include <opencv2/opencv.hpp>

class FaceDetector
{
public:
    FaceDetector(const std::string& cascade_filepath);
    void face_detect(const cv::Mat& input_image, std::vector<cv::Rect>& faces);

private:
    cv::CascadeClassifier cascade_classier;
};
