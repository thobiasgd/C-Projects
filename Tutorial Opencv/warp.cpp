#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

float w = 250, h = 350;
Mat matrix, imgWarp;

int main(){

    string path = "Resources/cards.jpg";
    Mat img = imread(path);

    Point2f src[4] = {{529,142},{771, 190}, {405, 395}, {674, 457}}; // Pontos float da imagem fonte
    Point2f dst[4] = {{0.0f,0.0f},{w, 0.0f}, {0.0f, h}, {w, h}}; // Pontos finais da imagem final 

    matrix = getPerspectiveTransform(src, dst);
    warpPerspective(img, imgWarp, matrix, Point(w, h));

    imshow("Imagem Warp",  imgWarp);
    waitKey(0);

}