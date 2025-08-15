#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

    string path = "Resources/test_video.mp4";
    VideoCapture cap(path); // Objeto de captura de vídeo
    Mat frame; // variável do tipo matriz criada pela opencv para lidar com imagens

    while (true){
        cap.read(frame);
        imshow("Video", frame);
        waitKey(1);
    }
    
}