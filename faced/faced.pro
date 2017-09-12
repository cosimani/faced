QT += widgets

LIBS += "/usr/lib/x86_64-linux-gnu/libopencv_core.so"
LIBS += "/usr/lib/x86_64-linux-gnu/libopencv_video.so"
LIBS += "/usr/lib/x86_64-linux-gnu/libopencv_highgui.so"
LIBS += "/usr/lib/x86_64-linux-gnu/libopencv_imgproc.so"
LIBS += "/usr/lib/x86_64-linux-gnu/libopencv_objdetect.so"

SOURCES += \
    main.cpp \
    config/config.cpp \
    app/app.cpp \
    camera/camera.cpp \
    haar/haar.cpp \
    features/features.cpp \
    app/navigator.cpp \
    app/image.cpp

HEADERS += \
    logger/logger.h \
    config/config.h \
    app/app.h \
    camera/camera.h \
    haar/haar.h \
    features/features.h \
    app/keys.h \
    app/navigator.h \
    app/image.h

DISTFILES += \
    ../project.config
