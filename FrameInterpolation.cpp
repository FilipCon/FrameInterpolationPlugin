#include "FrameInterpolation.h"

using namespace cv;

/**
 * https://github.com/Fju/slow-it-down/blob/master/main.cpp
 */
void interpolate(uchar* previous_image, uchar* current_image,
                 uchar* interpolated_image, int w, int h, double t) {
    Mat previousImage(h, w, CV_8UC3, (void*) previous_image);
    Mat currentImage(h, w, CV_8UC3, (void*) current_image);
    Mat mergedImage(h, w, CV_8UC3, (void*) interpolated_image);

    for (int i = 0; i < previousImage.rows; ++i) {
        for (int j = 0; j < previousImage.cols; ++j) {
            const auto& color1 = previousImage.at<Vec3b>(i, j);
            const auto& color2 = currentImage.at<Vec3b>(i, j);
            Vec3b merged_color;
            for (int c = 0; c < 3; ++c) {
                merged_color[c] =
                        std::floor(color1[c] * (1 - t) + color2[c] * t);
            }

            mergedImage.at<Vec3b>(i, j) = merged_color;
        }
    }
}
