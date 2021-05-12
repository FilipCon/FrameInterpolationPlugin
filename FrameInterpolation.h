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

extern "C" {
FrameInterpolation_API void interpolate(uchar*, uchar*, uchar*, int w, int h,
                                        double t);
}
