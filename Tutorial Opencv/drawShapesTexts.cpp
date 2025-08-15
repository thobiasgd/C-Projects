#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){

    // Criando uma imagem "do zero"
    Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255)); // #1 x da imagem - #2 y da imagem - #3 tamanho do byte e tipo de escala - #4 cor da imagem

    // Criando formas
    circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED); // #1 imagem input - #2 Centro do circulo - #3 raio - #4 Cor - #5 Grossura [FILLED para preencher]
    rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255,255), FILLED); // #1 imagem input - #2 Ponto Incial - #3 Ponto Final - #4 Cor - #5 Grossura [FILLED para preencher]
    line(img, Point(130, 296), Point(386, 296), Scalar(255, 255, 255), 2); // #1 imagem input - #2 Ponto Incial - #3 Ponto Final - #4 Cor - #5 Grossura

    // Inserindo Textos
    putText(img, "Murtaza's Workshop", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2); // #1 imagem input - #2 Texto - #3 Ponto Inicial - #4 Fonte - #5 Cor - #6 Grossura

    imshow("Imagem", img);
    waitKey(0);
}