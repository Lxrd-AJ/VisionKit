/**
 *
 * Written by AJ Ibraheem 
 * */

#include "vision.h"
#include "fake_blur.h"

#include <opencv2/opencv.hpp> //included because we use OpenCV's builtin Gaussian blur
#include <tuple> 

namespace vision { namespace common {

    cv::Mat blur(cv::Mat image, std::tuple<int,int> kernel_size){
        int x,y;
        std::tie (x,y) = kernel_size;
        cv::Mat result;
        cv::GaussianBlur(image, result, cv::Size(x,y), 0);
        return result;
    }
}}