# Faced

## Fundamentación teórica
En el área de Procesamiento Digital de Imágenes (PDI) existen numerosas técnicas para reconocer patrones. Este proyecto se enfoca principalmente en la detección de movimientos del rostro de una persona y muestra cómo es posible combinar dos técnicas completamente distintas para obtener una precisión mucho mayor. Las técnicas aplicadas son:

* Haar feature-based cascade classifiers
* Smoothed features extraction

### Haar feature-based cascade classifiers
Esta técnica nos brinda un punto de reconocimiento rápido pero bastante inestable. Tiene un gran rendimiento si es aplicada en interfaces de grandes segmentos.

### Smoothed features extraction
Esta técnica tiene un costo de procesamiento bastante más alto, pero brinda mayor precisión en el punto de reconocimiento. Es aplicable a control de sistemas que requieren precisión.

### Una solución híbrida
Es posible implementar una interfaz que combine estas dos técnicas y tenga un rendimiento mucho mayor tanto en precisión como en rapidez. Sobre los resultados de la primer detección inestable, se realiza un suavizado de puntos utilizando frames consecutivos y se aplica el reconocimiento de características sobre una porción de la imagen previamente segmentada.


