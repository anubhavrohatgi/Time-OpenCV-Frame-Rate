#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/opencv_modules.hpp>
#include "AssessTime.h"
#include <set>


using namespace std;
using namespace cv;


int main()
{
    cout << "Hello World!" << endl;

    vi::Utility::AssessTime tik("Mat");

    cv::Mat img = cv::imread("f:/13.jpg");

   // cv::Mat gray;
   tik.Start();
   cv::cvtColor(img,gray,cv::COLOR_BGR2GRAY);
   cv::GaussianBlur(gray, gray,cv::Size(7, 7), 1.5);
   cv::Canny(gray, gray, 0, 50);
   tik.stopAndgetTime();

   //tik.Reset();

   cv::UMat imgU,grayU;

   img.copyTo(imgU);

   vi::Utility::AssessTime tikU("UMAT");
   tikU.Start();
   cv::cvtColor(imgU, grayU, cv::COLOR_BGR2GRAY);
   cv::GaussianBlur(grayU, grayU,cv::Size(7, 7), 1.5);
   cv::Canny(grayU, grayU, 0, 50);
   tikU.stopAndgetTime();


  cv::imshow("Mat edges", gray);
  cv::waitKey(0);


   system("pause");
   return 0;
}

