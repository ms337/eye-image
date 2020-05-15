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

int Engine::process(int noOfDiv) //FILE inputImg)
{

    const int NO_OF_DIVISIONS = noOfDiv;
    Mat image;
    image = imread("./imgs/01.jpg"); //read the image to be broken down

    cout << image.size() << endl;

    int imgWidth = image.size().width; //get image width in pixels

    // imshow("Mask Image", mask);

    int segmentIndex = 0;

    Mat frames[NO_OF_DIVISIONS];

    int stride = imgWidth / NO_OF_DIVISIONS;

    for (int i = 0; i < NO_OF_DIVISIONS; i++)
    {
        cout << stride << endl;
        frames[i] = Mat(512, 512, CV_8UC1);

        Rect ROI(i * stride, 0, stride, 512); //selects region of interest

        //Creating a new mask based on ROI
        Mat mask(image.size(), CV_8UC1, Scalar::all(0));

        //Apply ROI mask to image
        mask(ROI).setTo(Scalar::all(255));

        image.copyTo(frames[i], mask);

        //Code snippet to check for each frame

        imshow("Original Image", image);
    }

    //Loop through frames and display image
    // for (int i = 0;; i = (i + 1) % NO_OF_DIVISIONS)
    // {
    //     imshow("Display Image", frames[i]);
    //     waitKey(1);
    // }

    VideoWriter outputVideo;
    double fps = 60;
    outputVideo.open("project.avi", VideoWriter::fourcc('F', 'M', 'P', '4'), fps, image.size(), true);

    if (!outputVideo.isOpened())
    {
        cout << "Could not open the output video for write: " << endl;
        return -1;
    }

    for (int i = 0; i < 1000 * NO_OF_DIVISIONS; i++)
    {
        outputVideo << frames[i % NO_OF_DIVISIONS];
    }

    cout << "Finished writing" << endl;
    return 0;
}
