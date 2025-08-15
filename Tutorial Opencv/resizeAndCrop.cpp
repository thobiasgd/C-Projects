#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    string path = "Resources/test.png";
    Mat img = imread(path);
    Mat imgResized, imgScaled, imgCroped;

    //cout << img.size() << endl;

    resize(img, imgResized, Size(640, 480)); // Converte a imagem para um número específico de largura e altura
    resize(img, imgScaled, Size(), 0.5, 0.5); // Converte o tamanho da largura e altura da imagem, em proporcional a um número

    // Trabalhando com ROI (Region of Interest)
    Rect roi(100, 100, 300, 250); // #1 x da imagem - 2# y da imagem - 3# tamanho x da ROI - 4# tamnho y da ROI
    imgCroped = img(roi);

    imshow("Imagem", img);
    imshow("Imagem Redimensionada", imgResized);
    imshow("Imagem Scalonada", imgScaled);
    imshow("ROI", imgCroped);
    waitKey(0);
}