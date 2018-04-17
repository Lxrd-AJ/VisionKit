/**
 *
 * Written by AJ Ibraheem 
 * */

#ifndef _FAKE_BLUR_H 
#define _FAKE_BLUR_H

#include "vision.h"
#include <opencv2/opencv.hpp>

#include <tuple> 

namespace vision { namespace common {
    /**
     * Fake function
     * Implements a gaussian blur on an image and returns it
     * \param image: The image to blur
     * \return result: The blurred image
     * */
    cv::Mat blur(cv::Mat image, std::tuple<int,int> kernel_size);
}}

#endif