#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    string path = "Resources/test.png";
    Mat img = imread(path); // variável do tipo matriz criada pela opencv para lidar com imagens
    imshow("Image", img); // Mostrando a imagem em si
    waitKey(0); // Impede que a imagem feche automaticamente ao abrir. Fecha ao clicar qualquer botão

}