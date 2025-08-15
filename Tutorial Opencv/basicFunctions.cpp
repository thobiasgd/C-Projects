#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    string path = "Resources/test.png";
    Mat img = imread(path);
    Mat imgGray, imgBlur, imgCanny, imgDil, imgErode; // Definindo a matriz de qualquer tipo de imagem do opencv

    cvtColor(img, imgGray, COLOR_BGR2GRAY);// Função que transforma de RGB para cinza
    GaussianBlur(img, imgBlur, Size(7,7), 5, 0); // Função que aplica Blur na imagem
    Canny(imgBlur, imgCanny, 25, 75); // Função de detecção de bordas

    Mat kernal = getStructuringElement(MORPH_RECT, Size(5,5)); // Matriz do kernel
    dilate(imgCanny, imgDil, kernal); // Função de dilatação de linhas
    erode(imgDil, imgErode, kernal); // Realiza a erosão em uma imagem

    imshow("Imagem", img);
    imshow("Cinza", imgGray);
    imshow("Imagem com Blur", imgBlur);
    imshow("Canny", imgCanny);
    imshow("Imagem Dilatada", imgDil);
    imshow("Imagem com Erosão", imgErode);
    waitKey(0);
}