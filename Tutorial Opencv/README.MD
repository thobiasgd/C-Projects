# Tutorial Básico de opencv para C++
Um tutorial com as principais funções da biblioteca do opencv para C++

## Importação de bibliotecas
Na maioria dos projetos que usam opencv, irá se usar os seguintes módulos da opencv:
```c++
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
```

## Abrir e Exibir
Para abrir um imagem e exibila em uma janela usa-se a seguinte estrutura na função main():
```c++
string path = "Resources/test.png";
Mat img = imread(path); // variável do tipo matriz criada pela opencv para lidar com imagens
imshow("Image", img); // Mostrando a imagem em si
waitKey(0); // Impede que a imagem feche automaticamente ao abrir. Fecha ao clicar qualquer botão
```

## Funções básicas
Em muitos projetos de processamento de imagens, usam-se em diversos momentos a conversão de escala de cores, efeitos de blur para diversos fins e também erosão e dilatação de linhas.
### Escala de cores
A seguinte função converte a imagem em outras escalas, deve-se olhar a documentação para o terceiro parâmetro que se refere a cada uma das escalas
```c++
cvtColor(img, imgGray, COLOR_BGR2GRAY);// Função que transforma de RGB para cinza
```
### Blur
O efeito de blur é útil para reduzir ruidos de imagens
```c++
GaussianBlur(img, imgBlur, Size(7,7), 5, 0); // Função que aplica Blur na imagem
```
### Detecção de bordas
Deve-se ressaltar que a seguinte função requere uma imagem na escala cor de cinza:
```c++
Canny(imgBlur, imgCanny, 25, 75); // Função de detecção de bordas
```
### Dilatação e Erosão
Para ambas as função, deve-se declarar um kernel, que é uma matriz que "roda" a imagem e vai aplicando o efeito. Também deve-se ressaltar que este kernel deve possuir seus dois valores ímpares. As duas imagens recebem um imput de imagem binária.
```c++
Mat kernal = getStructuringElement(MORPH_RECT, Size(5,5)); // Matriz do kernel
dilate(imgCanny, imgDil, kernal); // Função de dilatação de linhas
erode(imgDil, imgErode, kernal); // Realiza a erosão em uma imagem
```
## Tamnho e ROI
### Reescalonar Imagens
Para reescalonar imagens, usam-se duas técnicas. Ou o programador define um x e y específicos para largura e altura, ou escolher um valor k para a escala que é multiplicado pelo valor atual de largura e altura.
```c++
resize(img, imgResized, Size(640, 480)); // Converte a imagem para um número específico de largura e altura
resize(img, imgScaled, Size(), k, k); // Converte o tamanho da largura e altura da imagem, em proporcional a um número
```
### ROI (Region of Interest)
A função de ROI, nada mais é que um recorte da imagem. Defina-se um objeto do tipo retângulo (Rect) que é aplicado na nova matriz;
```c++
Mat imgResized, imgScaled, imgCroped;
Rect roi(100, 100, 300, 250); // #1 x da imagem - 2# y da imagem - 3# tamanho x da ROI - 4# tamnho y da ROI
imgCroped = img(roi);
```
## Formas e Textos
### Inserindo Formas Geométricas
As função de cada uma das formas geométricas são relativamente similares, apenas deve-se prestar atenção nos tipos de inputs de cada um dos parâmetros
```c++
circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED); // #1 imagem input - #2 Centro do circulo - #3 raio - #4 Cor - #5 Grossura [FILLED para preencher]
rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255,255), FILLED); // #1 imagem input - #2 Ponto Incial - #3 Ponto Final - #4 Cor - #5 Grossura [FILLED para preencher]
line(img, Point(130, 296), Point(386, 296), Scalar(255, 255, 255), 2); // #1 imagem input - #2 Ponto Incial - #3 Ponto Final - #4 Cor - #5 Grossura
```
### Textos
A diferênça da função de texto para das formas, é basicamente o tipo de fonte, que por sua vez pode ser encontrado na documentação.
```c++
putText(img, "Texto teste", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2); // #1 imagem input - #2 Texto - #3 Ponto Inicial - #4 Fonte - #5 Cor - #6 Grossura
```
## Warping 
Uma função interessante do mundo da visão computacional, é o warping. Uma técnica que permite trazer um objeto que está na perspectiva "diagonal", para uma perspectiva de "top view".
```c++
float w = 250, h = 350; // largura e altura da "nova" imagem
Mat matrix, imgWarp;
string path = "Resources/cards.jpg";
Mat img = imread(path);

Point2f src[4] = {{529,142},{771, 190}, {405, 395}, {674, 457}}; // Pontos float da imagem fonte
Point2f dst[4] = {{0.0f,0.0f},{w, 0.0f}, {0.0f, h}, {w, h}}; // Pontos finais da imagem final 

matrix = getPerspectiveTransform(src, dst);
warpPerspective(img, imgWarp, matrix, Point(w, h));
```
## Filtro de Cores
Para filtrar cores numa imagem, primeiramente instancia-se os valores minimos e máximos desejados da escala de cores HSV. Em seguida se converte a imagem em HSV e por fim usa-se a função inRange().
```c++
Mat matrix, imgHSV, mask, result; 
int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;

cvtColor(img, imgHSV, COLOR_BGR2HSV);

Scalar lower(hmin, smin, vmin);
Scalar upper(hmax, smax, vmax);
inRange(imgHSV, lower, upper, mask); // mask será uma matriz binária com os valores que estão de acordo com o filtro inRange()
bitwise_and(img, img, result, mask); // Faz a intersecção entre a imagem original e a máscara
```
### Trackbars
As trackbars são úteis para realizar a análise das cores desejadas, quando não se sabe qua valores deve-se usar no HSV. Para criar esta ferramenta, deve-se instanciar uma janela, e aribuir tracksbars para cada um dos valores desejados.
```c++
int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;

namedWindow("Trackbars", WINDOW_NORMAL); // Cria a janela
resizeWindow("Trackbars", 640, 200); // Redimensiona a janela

// Criando as trackbars em si
createTrackbar("Hue Min", "Trackbars", &hmin, 179); // Valores de Hue tem o máximo de 180
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
```
## Detecção de Contornos
O processo para detecção de contornos é um pouco mais complicado, mas vamos trabalhar apenas com o básico. Primeiramente cria-se as váriaveis de contrnos e hierarquia.
```c++
vector<vector<Point>> contours;
vector<Vec4i> hierarchy; // Basicamente Vec4i é um vetor padrão do opencv que possui 4 ints
```
Em seguida, aplica-se a função que realiza a busca dos contornos. O parâmetro 3 e 4 são referêntes ao método de procura.
```c++
findContours(imaDilation, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE); // Encontra os contornos
```
Por fim, desenha-se os contornos. Os arquivos `contourDetection.cpp` e `functions.cpp`, abordam algumas outras tecnicas interessantes envolvendo contornos.:
```c++
drawContours(imgDraw, contours, i, Scalar(255, 255, 0), 2); // Desenha os contornos #1 imagem final - 2# variável dos contornos - #3 cor - 4# grossura
```
## Detecção de objetos
Uma técnica de detecção de objetos que já vem padrão com a opencv, é a ténica de cascada. para isto, basta escolher um arquivo .xml do objeto desejado, e aplica-lo na função. Instancia-se um objeto da classe `CascadeClassifier`, que por sua vez recebe o local do arquivo.
```c++
CascadeClassifier faceCascade;
faceCascade.load("./Resources/haarcascade_frontalface_default.xml"); // abre o arquivo .xml

if (faceCascade.empty()){ cout << "XML file not loaded\n"; }  // Verifica se conseguiu abrir/encontrar o arquivo

vector<Rect> faces;
faceCascade.detectMultiScale(img, faces, 1.1, 10);
```
Em seguida, sugere-se desenhar um retângulo na face detectada. Nota-se que uma variável do tipo Rect, possui métodos para se obter os pontos de Top Left (tl) e Bottom Right (br).
```c++
for(int i = 0; i < faces.size(); i++){
    rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 2); // #1 imagem input - #2 Ponto Incial - #3 Ponto Final - #4 Cor - #5 Grossura [FILLED para preencher]
}
```
