#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){

    string path = "Resources/test.png";
    Mat img = imread(path);

    CascadeClassifier faceCascade;
    faceCascade.load("./Resources/haarcascade_frontalface_default.xml"); // abre o arquivo .xml

    if (faceCascade.empty()){ cout << "XML file not loaded\n"; }  // Verifica se conseguiu abrir/encontrar o arquivo

    vector<Rect> faces;
    faceCascade.detectMultiScale(img, faces, 1.1, 10);

    for(int i = 0; i < faces.size(); i++){
        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 2); // #1 imagem input - #2 Ponto Incial - #3 Ponto Final - #4 Cor - #5 Grossura [FILLED para preencher]
    }

    imshow("Imagem", img);
    waitKey(0);
}