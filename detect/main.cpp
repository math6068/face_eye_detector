#include <iostream>
#include <detector_lib/FaceDetector.hpp>
#include <detector_lib/EyesDetector.hpp>

int main(int argc, char* argv[])
{

    // Load image
    cv::Mat img = cv::imread(argv[1]);
    if (img.empty()) {
        std::cout << "Input image file not found " << std::endl;
        return 1;
    }

    // Initialize face detector and detect faces
    FaceDetector faceDetector("data/model_weight/haarcascade_frontalface_alt.xml");
    // Initialize eye detector
    EyeDetector eyesDetector("data/model_weight/eye.xml");
    
    // Detect faces in the input image
    std::vector<cv::Rect> faces = faceDetector.face_detect(img);
    
    // Draw rectangles around the detected faces
    // For each face, detect eyes
    for (cv::Rect face : faces) {
        cv::Mat face_roi = img(face);
        std::vector<cv::Rect> eyes = eyesDetector.eyes_detect(face_roi);

        // Draw rectangles around the detected eyes
        for (cv::Rect eye : eyes) {
            cv::rectangle(face_roi, eye, cv::Scalar(0, 255, 0), 2);
        }

        // Draw rectangle around the detected face
        cv::rectangle(img, face, cv::Scalar(255, 0, 0), 2);
    }

    cv::imwrite(argv[2], img);
    
    return 0;
}
