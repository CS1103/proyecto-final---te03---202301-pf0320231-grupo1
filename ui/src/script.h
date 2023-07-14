#include <cstring>
#include <iostream>
#include <vector>
#include "Pixel.h"

using namespace std;

string create_script(Pixel** pixelMatrix) {
    string scriptString =
        "import numpy as np\n"
        "import tensorflow as tf\n"
        "from tensorflow.keras.models import load_model\n"
        "matrix = [";
    for (int i = 0; i < 256; i++) {
        scriptString += "[";
        for (int j = 0; j < 256; j++) {
            scriptString += "[";
            scriptString += std::to_string(float(pixelMatrix[i][j].r) / 255.0);
            scriptString += ",";
            scriptString += std::to_string(float(pixelMatrix[i][j].g) / 255.0);
            scriptString += ",";
            scriptString += std::to_string(float(pixelMatrix[i][j].b) / 255.0);
            scriptString += "]";
            if (j != 255)
                scriptString += ",";
        }
        scriptString += "]";
        if (i != 255)
            scriptString += ",";
    }
    scriptString +=
        "]\n"
        "matrix = np.expand_dims(matrix, axis=0)\n"
        "model = load_model('model2.h5')\n"
        "yhat = model.predict(matrix)*255\n"
        "print('Predicted: ', yhat)\n"
        "if yhat > 0.5:\n"
        "    print('Vehículo')\n"
        "else:\n"
        "    print('No vehículo')\n";
    return scriptString;
}
