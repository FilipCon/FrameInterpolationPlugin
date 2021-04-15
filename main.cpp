#include "FrameInterpolation.h"
#include "Measure.h"
#include "Settings.h"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    // load images
    Mat prevFrame = imread(std::string(DATA_DIR + "/I2_0.png"));
    Mat frame = imread(std::string(DATA_DIR + "/I2_1.png"));

    // set number of interpolation
    int totalTimeSteps = 16;

    // set final images
    Mat result(frame.rows, frame.cols, CV_8UC3);

    for (int t = 0; t < totalTimeSteps; ++t) {
        double timeStep = 1.0 / totalTimeSteps * t;

        START_CHRONO();
        // auto output = interpolate(frame.data, prevFrame.data, frame.cols,
        //                           frame.rows, timeStep);
        // // 344064
        // memcpy(result.data, output,
        //        3 * frame.rows * frame.cols * sizeof(uchar));
        // freeMem(output);
        END_CHRONO();

        imwrite(DATA_DIR + "/I2_X_" + to_string(t) + ".png", result);
    }
    return 0;
}
