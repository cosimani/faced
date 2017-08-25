QT += widgets

SOURCES += \
    main.cpp \
    config/config.cpp \
    app/widgets/widgets.cpp \
    app/app.cpp \
    camera/camera.cpp

HEADERS += \
    logger/logger.h \
    config/config.h \
    app/widgets/widgets.h \
    app/app.h \
    camera/camera.h

DISTFILES += \
    ../project.config
