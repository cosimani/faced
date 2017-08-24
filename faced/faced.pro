QT += widgets multimedia

LIBS += "/usr/lib/x86_64-linux-gnu/libopencv_core.so"
LIBS += "/usr/lib/x86_64-linux-gnu/libopencv_highgui.so"
LIBS += "/usr/lib/x86_64-linux-gnu/libopencv_imgproc.so"
LIBS += "/usr/lib/x86_64-linux-gnu/libopencv_objdetect.so"

SOURCES += \
    config/config.cpp \
    interface/block.cpp \
    interface/image.cpp \
    interface/interface.cpp \
    processor/camera.cpp \
    theme/colorizer.cpp \
    theme/theme.cpp \
    main.cpp

HEADERS += \
    config/config.h \
    interface/block.hpp \
    interface/image.hpp \
    interface/interface.hpp \
    logger/logger.h \
    processor/camera.hpp \
    theme/colorizer.hpp \
    theme/theme.hpp \
    common.hpp

FORMS += \
    interface/block.ui \
    interface/interface.ui

DISTFILES += \
    project.config
