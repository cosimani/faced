# Faced - Generics

Faced Generics brinda un conjunto de clases que permiten incluir la detección del rostro mediante <b>Haar Features-Based Cascade Classifiers</b> y <b>Smoothed Features Extraction</b>.

## Cómo usarlo

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
connect(detector, SIGNAL(point(QPoint)), SLOT(mySlot(QPoint)))
```

## Teoría

En el área de Procesamiento Digital de Imágenes (PDI) existen numerosas técnicas para reconocer patrones. Este proyecto se enfoca principalmente en la detección de movimientos del rostro de una persona y muestra cómo es posible combinar dos técnicas completamente distintas para obtener una precisión mucho mayor. Las técnicas aplicadas son:

* Haar Features-Based Cascade Classifiers
* Smoothed Features Extraction

### Haar Features-Based Cascade Classifiers

Esta técnica nos brinda un punto de reconocimiento rápido pero bastante inestable. Tiene un gran rendimiento si es aplicada en interfaces de grandes segmentos.

### Smoothed Features Extraction

Esta técnica tiene un costo de procesamiento bastante más alto, pero brinda mayor precisión en el punto de reconocimiento. Es aplicable a control de sistemas que requieren precisión.