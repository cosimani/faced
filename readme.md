# Faced

Faced Generics brinda un conjunto de clases que permiten incluir la detección del rostro mediante <b>Haar Features-Based Cascade Classifiers</b> y <b>Smoothed Features Extraction</b>.

Se utilizaron las siguientes herramientas:

* [C++](https://es.wikipedia.org/wiki/C%2B%2B)
* [Qt Creator](https://www.qt.io/ide/)
* [Open CV](http://opencv.org/)
* [Github](https://github.com/)

### Cómo usarlo

1. Instanciar el tipo de detección deseado

```c++
Haar *detector = new Haar();
```

2. Iniciar tracking

```c++
detector->startTracking();
```

2. Procesar la señal point

```c++
connect(haar, SIGNAL(point(QPoint)), SLOT(mySlot(QPoint)))
```


## Estructura

![Estructura](https://k60.kn3.net/E/2/F/0/8/E/EEF.png)

El proyecto está compuesto por varios módulos:

* <b>Camera</b> permite el tracking de los frames de la cámara web.
* <b>Config</b> aplica las configuraciones específicas del usuario a la instancia en ejecución.
* <b>Features</b> implementa el procesamiento de Smoothed Features Extraction.
* <b>Haar</b> implementa el procesamiento de Haar Features-Based Cascade Classifiers.
* <b>Logger</b> para el manejo de registros.

## Fundamentación teórica

En el área de Procesamiento Digital de Imágenes (PDI) existen numerosas técnicas para reconocer patrones. Este proyecto se enfoca principalmente en la detección de movimientos del rostro de una persona y muestra cómo es posible combinar dos técnicas completamente distintas para obtener una precisión mucho mayor. Las técnicas aplicadas son:

* Haar Features-Based Cascade Classifiers
* Smoothed Features Extraction

### Haar Features-Based Cascade Classifiers

Esta técnica nos brinda un punto de reconocimiento rápido pero bastante inestable. Tiene un gran rendimiento si es aplicada en interfaces de grandes segmentos.

### Smoothed Features Extraction

Esta técnica tiene un costo de procesamiento bastante más alto, pero brinda mayor precisión en el punto de reconocimiento. Es aplicable a control de sistemas que requieren precisión.