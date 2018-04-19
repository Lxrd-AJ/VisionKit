
#include "vision.h"
#include "common/fake_blur.h"
#include <opencv2/opencv.hpp>
#include <tuple>
#include <iostream>

// using namespace vision;
namespace common = vision::common;

int main(int argc, char** argv){
    cv::Mat image = cv::imread("./bp.jpg");
    cv::resize(image, image, cv::Size(800,600));
    cv::namedWindow("Input_Image");
    cv::imshow("Input_Image", image);

    auto result = common::blur(image, std::make_tuple(5,5));
    // std::cout << result << std::endl;

    cv::namedWindow("Result");
    cv::imshow("Result", result);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}