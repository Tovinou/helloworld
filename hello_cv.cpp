#include <iostream>
#include "opencv2/highgui.hpp"
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    /* Create an empty image */
    cv::Mat img(500, 1000, CV_8UC3, cv::Scalar(0, 0, 100));
    if (img.empty())
    {
        std::cout << "\n Image is empty, something gone wrong.\n";
        return -1;
    }

    // Use cv::WINDOW_AUTOSIZE instead of CV_WINDOW_AUTOSIZE
    cv::namedWindow("My_Screen", cv::WINDOW_AUTOSIZE);
    cv::Point org(30, 100);
    
    // You can keep using cv::FONT_HERSHEY_SCRIPT_COMPLEX as it is a valid option
    cv::putText(img, "A Perfect Compiled World", org,
                cv::FONT_HERSHEY_SCRIPT_COMPLEX, 2.1,
                cv::Scalar(0, 0, 255), 2, cv::LINE_AA);

    cv::imshow("My_Screen", img);
    cv::waitKey(0);
    cv::destroyWindow("My_Screen");
    return 0;
}
