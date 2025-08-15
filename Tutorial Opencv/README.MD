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
