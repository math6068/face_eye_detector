#include <detector_lib/FaceDetector.hpp>
#include <detector_lib/EyesDetector.hpp>
#include <gtest/gtest.h>

TEST(EyesDetectionTest, DetectEyes)
{
    // Load the input image
    cv::Mat img = cv::imread("data/CelebA_sample_image/sample_image.png");
    if (img.empty()) {
        std::cout << "Input image file not found " << std::endl;
    }
    // Initialize face detector and detect faces
    FaceDetector faceDetector("data/model_weight/haarcascade_frontalface_alt.xml");
    // Initialize eye detector
    EyeDetector eyesDetector("data/model_weight/eye.xml");
    
    // Detect faces in the input image
    std::vector<cv::Rect> faces = faceDetector.face_detect(img);

    for (cv::Rect face : faces) {
        cv::Mat face_roi = img(face);
        std::vector<cv::Rect> eyes = eyesDetector.eyes_detect(face_roi);
        ASSERT_GT(eyes.size(), 1);
    }
}