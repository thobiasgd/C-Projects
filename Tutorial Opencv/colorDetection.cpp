#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat matrix, imgHSV, mask, result;
int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;

int main(){

    string path = "Resources/lambo.png";
    Mat img = imread(path);

    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    Scalar lower(hmin, smin, vmin);
    Scalar upper(hmax, smax, vmax);
    inRange(imgHSV, lower, upper, mask);

    bitwise_and(img, img, result, mask); 

    imshow("Imagem", img);
    imshow("Imagem HSC", imgHSV);
    imshow("Imagem Máscara", mask);
    imshow("Resultado", result);
    waitKey(0);

}