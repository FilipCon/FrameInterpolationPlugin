#include "FrameInterpolation.h"
#include "Measure.h"
#include "Settings.h"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    // load images
    auto videoName = std::string(DATA_DIR + "/Las-Vegas-short.webm");
    VideoCapture capture(videoName);
    Mat frame, prevFrame;
    capture >> frame;

    // set final images
    Mat result(frame.rows, frame.cols, frame.type());

    // set number of interpolation
    int totalTimeSteps = 16;

    while (true) {
        capture >> frame;
        if (!frame.data) break;

        if (prevFrame.data) {
            for (int t = 0; t <= totalTimeSteps; ++t) {
                double timeStep = 1.0 / totalTimeSteps * t;

                START_CHRONO();
                interpolate(prevFrame.data, frame.data, result.data, frame.cols,
                            frame.rows, timeStep);
                END_CHRONO();

                imshow("Test", result);
                waitKey(1);
            }
        }
        swap(frame, prevFrame);
    }
    capture.release();

    return 0;
}
