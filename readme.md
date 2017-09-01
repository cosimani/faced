# Faced

Faced es un proyecto que combina <b>Haar Features-Based Cascade Classifiers</b> con <b>Smoothed Features Extraction</b> para el control de una <b>Interfaz Natural de Usuario</b> con movimientos del rostro.

Se utilizaron las siguientes herramientas:

* [C++](https://es.wikipedia.org/wiki/C%2B%2B)
* [Qt Creator](https://www.qt.io/ide/)
* [Open CV](http://opencv.org/)
* [Github](https://github.com/)

## Estructura

![Estructura](https://k60.kn3.net/E/2/F/0/8/E/EEF.png)

El proyecto está compuesto por varios módulos:

* <b>App</b> separa la lógica de la aplicación de las funcionalidades genéricas.
* <b>Camera</b> permite el tracking de los frames de la cámara web.
* <b>Config</b> aplica las configuraciones específicas del usuario a la instancia en ejecución.
* <b>Features</b> implementa el procesamiento de Smoothed Features Extraction.
* <b>Haar</b> implementa el procesamiento de Haar Features-Based Cascade Classifiers.
* <b>Logger</b> para el manejo de registros.

También existen folders y archivos dedicados:

* <b>Classifiers</b> es un directorio donde se guardan los clasificadores a utilizar por el módulo Haar.
* <b>Example</b> es un directorio para navegación en la demostración de ejemplo.
* <b>Project.config</b> es el archivo de configuración aplicable por el módulo Config.

## Fundamentación teórica

En el área de Procesamiento Digital de Imágenes (PDI) existen numerosas técnicas para reconocer patrones. Este proyecto se enfoca principalmente en la detección de movimientos del rostro de una persona y muestra cómo es posible combinar dos técnicas completamente distintas para obtener una precisión mucho mayor. Las técnicas aplicadas son:

* Haar Features-Based Cascade Classifiers
* Smoothed Features Extraction

### Haar Features-Based Cascade Classifiers

Esta técnica nos brinda un punto de reconocimiento rápido pero bastante inestable. Tiene un gran rendimiento si es aplicada en interfaces de grandes segmentos.

### Smoothed Features Extraction

Esta técnica tiene un costo de procesamiento bastante más alto, pero brinda mayor precisión en el punto de reconocimiento. Es aplicable a control de sistemas que requieren precisión.

### Una solución híbrida

Es posible implementar una interfaz que combine estas dos técnicas y tenga un rendimiento mucho mayor tanto en precisión como en rapidez. Sobre los resultados de la primer detección inestable, se realiza un suavizado de puntos utilizando frames consecutivos y se aplica el reconocimiento de características sobre una porción de la imagen previamente segmentada.


