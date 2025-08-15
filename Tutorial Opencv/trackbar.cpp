#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat matrix, imgHSV, mask;
int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;

int main(){

    string path = "Resources/lambo.png";
    Mat img = imread(path);
    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    namedWindow("Trackbars", WINDOW_NORMAL);
    resizeWindow("Trackbars", 640, 200); 

    // Criando as trackbars em si
    createTrackbar("Hue Min", "Trackbars", &hmin, 179);
    createTrackbar("Sat Min", "Trackbars", &smin, 255);
    createTrackbar("Val Min", "Trackbars", &vmin, 255);

    createTrackbar("Hue Max", "Trackbars", &hmax, 179);
    createTrackbar("Sat Max", "Trackbars", &smax, 255);
    createTrackbar("Val Max", "Trackbars", &vmax, 255);

    while(true){

        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        inRange(imgHSV, lower, upper, mask);

        imshow("Imagem", img);
        imshow("Imagem HSC", imgHSV);
        imshow("Imagem Máscara", mask);
        waitKey(1);

    }

}