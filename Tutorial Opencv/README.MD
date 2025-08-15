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
