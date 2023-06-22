# CNN para clasificación de imágenes

### Quiénes Somos

Somos un grupo de estudiantes de UTEC quienes realizaran este proyecto para el curso
CS2013 - Programación III

### Acerca del Proyecto

El siguiente repositorio es un proyecto sobre la implementación de una red neuronal convolucionaria (CNN) en C++ para clasificar imagenes de diferentes categorías como animales o vehículos. Incluimos el diseño de la arquitectura de la red neuronal, la implementación de los pases hacia adelante y hacia atrás, y como optimizamos la red utilizando el descenso de gradiente.

## Características Principales

- Uso de [TensorFlow](https://www.tensorflow.org/?hl=es-419) (Python) para entrenamiento.
- Uso de [TensorFlow Lite](https://www.tensorflow.org/lite/guide/inference?hl=es-419#load_and_run_a_model_in_c) (C++) para realizar inferencia.
- Uso de [Qt](https://www.qt.io/) (C++) para construir una UI simple.

## Pasos a Seguir

### 1. Entrenar la CNN

- Instalar `TensorFlow` para Python.
- Recolectar la dataset para entrenamiento.
- Separamos 60% de las imagenes del dataset para el entrenamiento, 40% para el testing.
- Creamos un proyecto de python.
- Importar `tensorflow.keras` para realizar el pre-procesamiento de imágenes, "augmentation" de data y cargar la arquitectura `MobileNetV2`.
- Definimos los parámetros de deep learning (epochs, learning rate, etc.).
- Compilamos nuestra "network" de entrenamiento.
- Realizamos el fine-tuning a `MobileNetV2`.
- Con mathplotlib revisamos las curvas de aprendizaje y su evolución con cada regresión (epoch).
- Una vez listo, exportamos el modelo en formato `.tflite` en nuestro directorio del proyecto de C++.


### 2. Crear un programa en C++ que use los pesos de la CNN, reciba una imagen como parametro, y retorne la inferencia.

- Incluimos las librerías de TensorFlow Lite, clonando su repositorio en nuestro directorio del proyecto.
- Vinculamos las librerias a nuestro ejecutable en el `CMakeLists.txt`.
- En nuestro main.cpp, creamos una funcion `int main(int argc, char **argv)`, que reciba como parámetro una cadena de caracteres que contiene la dirección de la imagen a ser procesada.
- Creamos un puntero inteligente de una instancia de la clase `tflite::FlatBufferModel`, la cual recibe el modelo creado anteriormente.
- Creamos un puntero inteligente además a `tflite::Interpreter`, clase que se encarga de ejecutar el modelo.
- Recibimos los parámetros al leer la imagen, como su alto, ancho, a través del `Interpreter`.
- Adaptamos los parámetros de la imagen para que sea legible por el modelo.
- Llamamos al método `Invoke()` de `Interpreter` para que nos retorne un arreglo con los resultados, y un vector con los valores de certeza.
- Obtenemos el resultado cuya certeza sea la máxima.
- Retornamos el resultado.
- Compilamos el código y dejamos el ejecutable en un directorio desde el que pueda ser llamado.


### 3. Crear una interfaz en C++ que reciba una imagen como entrada, llame al ejecutable previo, y muestre la inferencia al usuario.

- Incluimos las librerías de Qt para interfaz gráfica y archivos, clonando su repositorio en nuestro directorio del proyecto.
- Vinculamos las librerías a nuestro ejecutable en el `CMakeLists.txt`.
- Creamos una función `main()` que sea un loop continuo.
- Creamos una instancia de una ventana con un widget que llame a un selector de imagenes.
- Creamos una función para cuando el usuario selecciona una imagen, se copia dentro de un directorio dedicado en la carpeta del proyecto.
- Vinculamos el boton de Qt con la función para copiar el archivo.
- Usando la función `system()`, la aplicación de la interfaz gráfica llama al ejecutable de la CNN y le pasa como atributo la ruta del nuevo archivo.
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
```rust
todo!();
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
- TensorFlowLite para C++ - https://www.tensorflow.org/lite/guide/inference?hl=es-419#load_and_run_a_model_in_c
- Guia Python CNN - https://pyimagesearch.com/2020/05/04/covid-19-face-mask-detector-with-opencv-keras-tensorflow-and-deep-learning/
- Documentación de Qt - https://wiki.qt.io/Qt_for_Beginners

# Rubrica
https://utec.instructure.com/courses/11683/files/2229177?module_item_id=1178749
https://utec.instructure.com/courses/11683/files/2233166?module_item_id=1179605
