#include "Engine.h"

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

Engine::Engine(/* args */)
{
}

Engine::~Engine()
{
}

void Engine::process() //FILE inputImg)
{
    Mat image;
    image = imread("./imgs/01.jpg");

    cout << image.size() << endl;

    //Creating the Mask`
    //Selecting region of  interest rectangle
    Rect ROI(0, 0, 100, 512);

    Mat mask(image.size(), CV_8UC1, Scalar::all(0));
    mask(ROI).setTo(Scalar::all(255));
    // imshow("Sel", mask);

    //Applying the Mask
    Mat imageDest = Mat(512, 512, CV_8UC3);
    image.copyTo(imageDest, mask);

    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Original Image", image);
    imshow("Display Image", imageDest);

    waitKey(0);
}