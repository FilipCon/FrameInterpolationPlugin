#pragma once

#include "opencv2/opencv.hpp"

#ifdef WIN32
#    ifdef FrameInterpolation_EXPORTS
#        define FrameInterpolation_API __declspec(dllexport)
#    else
#        define FrameInterpolation_API __declspec(dllimport)
#    endif
#else
#    define FrameInterpolation_API
#endif // WIN32

struct Color32 {
    uchar red;
    uchar green;
    uchar blue;
    uchar alpha;
};

cv::Mat _currentFrame;

extern "C" {
FrameInterpolation_API void interpolate(Color32* current_image,
                                        Color32* next_image, int w, int h,
                                        double t);


FrameInterpolation_API void GetRawImageBytes(unsigned char* data, int width, int height)
{
   /* //Resize Mat to match the array passed to it from C# */
   /*  cv::Mat resizedMat(height, width, _currentFrame.type()); */
   /*  cv::resize(_currentFrame, resizedMat, resizedMat.size(), cv::INTER_CUBIC); */

   /*  //You may not need this line. Depends on what you are doing */
   /*  cv::imshow("Nicolas", resizedMat); */

   /*  //Convert from RGB to ARGB */
   /*  cv::Mat argb_img; */
   /*  cv::cvtColor(resizedMat, argb_img, cv::COLOR_RGB2BGRA); */
   /*  std::vector<cv::Mat> bgra; */
   /*  cv::split(argb_img, bgra); */
   /*  std::swap(bgra[0], bgra[3]); */
   /*  std::swap(bgra[1], bgra[2]); */
   /*  std::memcpy(data, argb_img.data, argb_img.total() * argb_img.elemSize()); */
}
/* FrameInterpolation_API void freeMem(uchar* arrayPtr); */

/* FrameInterpolation_API void testPlugin(); */
}
