# CNN para clasificación de imágenes

### Quiénes Somos

Somos un grupo de estudiantes de UTEC quienes realizaran este proyecto para el curso
CS2013 - Programación III

### Acerca del Proyecto

El siguiente repositorio es un proyecto sobre la implementación de una red neuronal convolucionaria (CNN) en C++, creada y entrenada en python para clasificar imagenes de vehículos y no vehículos.

## Características Principales

- Uso de [TensorFlow](https://www.tensorflow.org/?hl=es-419) (Python) para entrenamiento y creación de la red neuronal
- Uso de [Python.h] (C++) para transformar las imágenes a matrices y realizar el paso de imágenes al modelo, por concurrencia.
- Uso de [wxWidgets](https://www.wxwidgets.org/) (C++) para construir una UI simple.

## Pasos a Seguir

### 1. Entrenar la CNN

- Instalar `TensorFlow` para Python.
- Recolectar la dataset para entrenamiento.
- Separamos 60% de las imagenes del dataset para el entrenamiento, 40% para el testing.
- Creamos un proyecto de python.
- Importar `tensorflow.keras` para realizar el pre-procesamiento de imágenes, "augmentation" de data y cargar la arquitectura `MobileNetV2`.
- Definimos los parámetros de deep learning (epochs, learning rate, etc.).
- Compilamos nuestra "network" de entrenamiento.
- Con mathplotlib revisamos las curvas de aprendizaje y su evolución con cada regresión (epoch).


### 2. Crear un programa en C++ que la CNN, reciba una imagen como parametro, y retorne la inferencia.

- Incluimos el header file `Python.h`, el cuál viene con la instalación de python, permite usar python embebido en c++.
- Vinculamos las librerias a nuestro ejecutable en el `CMakeLists.txt`.
- En nuestro main.cpp, creamos una funcion `int main(int argc, char **argv)`, que reciba como parámetro una cadena de caracteres que contiene la dirección de la imagen a ser procesada.
- Adaptamos los parámetros de la imagen(255x255) para que sea legible por el modelo.
- Creamos la estructura `pixel` para poder utilizar métodos de wx para poder identificar color pixel por pixel de la imagen y así realizar una matriz.
- Utilizamos el python embebido para mostrar la matriz en consola. 
- Convertimos la matriz a numpy arrays, para la lectura por parte del modelo.
- Obtenemos el resultado.
- Retornamos el resultado y lo mostramos en pantalla.


### 3. Crear una interfaz en C++ que reciba una imagen como entrada, llame al ejecutable previo, y muestre la inferencia al usuario.

- Incluimos las librerías de wxWidgets para interfaz gráfica y archivos, clonando su repositorio en nuestro directorio del proyecto.
- Vinculamos las librerías a nuestro ejecutable en el `CMakeLists.txt`.
- Creamos una clase `MyApp` que tenga un método booleano virtual, esta es una clase heredada de wxApp.
- Creamos una instancia de una ventana con un widget que llame a un selector de imagenes.
- Creamos una función para cuando el usuario selecciona una imagen, se copia dentro de un directorio dedicado en la carpeta del proyecto.
- Vinculamos el boton de wxWidgets con la función para copiar el archivo.
- Guardamos la respuesta en una variable `result`, la cual se muestra en la interfaz gráfica de ser válida.


## Guía de instalación

Para clonar y ejecutar nuestro trabajo necesitas [Git](https://git-scm.com) y [C++ compiler](https://www.cs.odu.edu/~zeil/cs250PreTest/latest/Public/installingACompiler/#installing-a-c-compiler-on-microsoft-windows) (recomendamos instalar xcode cli tools si estas en mac os). Después de cumplir con los requisitos puedes ejecutar lo siguiente desde tu línea de comandos:

```bash
# Clona este repositorio
$ git clone https://github.com/CS1103/proyecto-final---te03---202301-pf0320231-grupo1.git
```

```bash
# Si tienes una clave SSH
$git clone git@github.com:CS1103/proyecto-final---te03---202301-pf0320231-grupo1.git
```

## Instrucciones de uso
### Linux y MacOSX
```bash
# Una vez clonado el repositorio ingresamos a el con cd
$ cd proyecto-final--te03--202301-pf0320231-grupo1
# ingresamos a la carpeta ui
$ cd ui
$ cmake .
$ cmake --build .
# si es linux
$ ./subprojects/Build/wx_cmake_template_core/main
# si es mac
$ ./subprojects/Build/wx_cmake_template_core/main.app/Contents/MacOS/main
# Esto debido a que macOSX interpreta nuestro trabajo como una aplicación añadiendo el .app

```

## Diagramas
```rust
todo!();
```

## Autores

- _Anlec(Marcelo Chincha)_
- _slamgLuke(Lucas Carranza)_
- _Adrian Cespedes(Adrian Céspedes)_
- _Hyp3Boy(Lenin Chavez)_

## Licencia

[MIT](https://choosealicense.com/licenses/mit/)

## Bibliografía
- Python embedding en C++ - https://docs.python.org/3/extending/embedding.html
- Guia Python CNN - https://pyimagesearch.com/2020/05/04/covid-19-face-mask-detector-with-opencv-keras-tensorflow-and-deep-learning/
- Documentación de wxWidgets - https://www.wxwidgets.org/docs/book/

# Rubrica
https://utec.instructure.com/courses/11683/files/2229177?module_item_id=1178749
https://utec.instructure.com/courses/11683/files/2233166?module_item_id=1179605
