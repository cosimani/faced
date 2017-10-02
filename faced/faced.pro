QT += widgets

LIBS += "/usr/lib/x86_64-linux-gnu/libopencv_core.so"
LIBS += "/usr/lib/x86_64-linux-gnu/libopencv_video.so"
LIBS += "/usr/lib/x86_64-linux-gnu/libopencv_highgui.so"
LIBS += "/usr/lib/x86_64-linux-gnu/libopencv_imgproc.so"
LIBS += "/usr/lib/x86_64-linux-gnu/libopencv_objdetect.so"

SOURCES += \
    main.cpp \
    detector/camera.cpp \
    detector/config.cpp \
    detector/features.cpp \
    detector/haar.cpp

HEADERS += \
    detector/camera.h \
    detector/config.h \
    detector/features.h \
    detector/haar.h \
    example.h \
    detector/logger.h
