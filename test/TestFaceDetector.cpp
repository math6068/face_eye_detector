#include "../include/FaceDetector.hpp"
#include <gtest/gtest.h>

TEST(FaceDetectionTest, DetectFaces)
{
    // Load the input image
    cv::Mat inputImage = cv::imread("input.jpg");

    // Create a face detector
    FaceDetector faceDetector("haarcascade_frontalface_alt.xml");

    // Detect faces in the input image
    std::vector<cv::Rect> faces;
    faceDetector.face_detect(inputImage, faces);

    // Check that at least one face was detected
    ASSERT_GT(faces.size(), 0);

    // // Draw rectangles around the detected faces
    // for (int i = 0; i < faces.size(); i++)
    // {
    //     cv::rectangle(inputImage, faces[i], cv::Scalar(0, 255, 0), 2);
    // }

    // // Save the output image
    // cv::imwrite("output.jpg", inputImage);
}