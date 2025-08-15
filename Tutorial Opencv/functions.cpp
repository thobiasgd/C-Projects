#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include "functions.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void getContours(Mat imaDilation, Mat imgDraw){

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy; // Basicamente Vec4i é um vetor padrão do opencv que possui 4 ints

    findContours(imaDilation, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE); // Encontra os contornos

    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRectangle(contours.size());
    string objectType;

    for (int i = 0; i < contours.size(); i++){ // Construindo filtro de tamanho de contorno
        int area = contourArea(contours[i]);
        //cout << area << endl;
        if (area > 1000){
            float perimeter = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02*perimeter, true);
            //drawContours(imgDraw, contours, i, Scalar(255, 0, 255), 5); // Desenha os contornos
            boundRectangle[i] = boundingRect(conPoly[i]);
            
            int objCorner = (int)conPoly[i].size();

            if (objCorner == 3){objectType = "Triangle";}
            else if (objCorner == 4){
                float aspectRatio = (float)boundRectangle[i].width / (float)boundRectangle[i].height;
                if (aspectRatio > 0.95 && aspectRatio < 1.05){objectType = "Square";}
                else {objectType = "Rectangle";}
            }
            else if (objCorner > 4){objectType = "Circle";}

            drawContours(imgDraw, conPoly, i, Scalar(255, 255, 0), 2); // Desenha os contornos
            rectangle(imgDraw, boundRectangle[i].tl(), boundRectangle[i].br(), Scalar(0, 255, 0), 5);
            putText(imgDraw, objectType, {boundRectangle[i].x, boundRectangle[i].y + 20}, 
                    FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2); // #1 imagem input - #2 Texto - #3 Ponto Inicial - #4 Fonte - #5 Cor - #6 Grossura
        }
    }

}