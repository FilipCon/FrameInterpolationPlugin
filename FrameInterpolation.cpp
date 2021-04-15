#include "FrameInterpolation.h"

using namespace cv;

void interpolate(Color32* current_image, Color32* next_image, int w, int h,
                 double t) {
    Mat currentImage(h, w, CV_8UC4, current_image);
    Mat nextImage(h, w, CV_8UC4, next_image);

    // auto merged_image = new uchar[h * w * 4];
    // Mat mergedImage(h, w, CV_8UC4, (void*) merged_image);

    // for (int i = 0; i < currentImage.rows; ++i) {
    //     for (int j = 0; j < currentImage.cols; ++j) {
    //         const auto& color1 = currentImage.at<Vec3b>(i, j);
    //         const auto& color2 = nextImage.at<Vec3b>(i, j);
    //         Vec3b merged_color;
    //         for (int c = 0; c < 3; ++c) {
    //             merged_color[c] =
    //                     std::floor(color1[c] * (1 - t) + color2[c] * t);
    //         }

    //         mergedImage.at<Vec3b>(i, j) = merged_color;
    //     }
    // }
    // return mergedImage.data;
}

// void freeMem(uchar* arrayPtr) { delete[] arrayPtr; }

// void testPlugin() {}
