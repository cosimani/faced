QT += widgets multimedia opengl

# La siguiente macro es para poder crear el Portable instalador. Cambia la carpeta del proyecto .. por .
# Se usa en common.hpp
DEFINES += NO_PORTABLE

# Con Speech o no
#DEFINES += CON_SPEECH

exists( /usr/local/lib/libopencv* )  {
    message( "Posiblemente sea la compu de Cesar" )

    # cesar
    unix:DIR_OPENCV_LIBS = /usr/local/lib

}

! exists( /usr/local/lib/libopencv* )  {
    message( "Posiblemente sea la compu de Emi" )

    # emi
    unix:DIR_OPENCV_LIBS = /usr/lib/x86_64-linux-gnu
}


#unix:DIR_OPENCV_LIBS = /usr/local/lib
unix:DIR_OTHER_LIBS = /usr/lib/x86_64-linux-gnu

unix:INCLUDEPATH += "/usr/include/GL/"

unix:LIBS += -L$$DIR_OPENCV_LIBS

unix:LIBS += -lopencv_core \
             -lopencv_highgui \
             -lopencv_imgproc \
             -lopencv_objdetect \
#             -lopencv_calib3d \
#             -lopencv_ml \
#             -lopencv_video \
#             -lopencv_features2d \
#             -lopencv_flann \
#             -lopencv_photo \
#             -lopencv_stitching \
#             -lopencv_superres \
#             -lopencv_video \
#             -lopencv_videostab \
#             -lopencv_imgcodecs \
             -lopencv_videoio \
#             -lopencv_bgsegm

unix:LIBS += "$$DIR_OTHER_LIBS/libespeak.so"


win32:DIR_OPENCV_LIBS = C:/Qt/OpenCV-3.1.0

win32:INCLUDEPATH += "$$DIR_OPENCV_LIBS/opencv/sources/include"
win32:INCLUDEPATH += "$$DIR_OPENCV_LIBS/opencv/sources/modules/core/include"
win32:INCLUDEPATH += "$$DIR_OPENCV_LIBS/opencv/sources/modules/imgproc/include"
win32:INCLUDEPATH += "$$DIR_OPENCV_LIBS/opencv/sources/modules/video/include"
win32:INCLUDEPATH += "$$DIR_OPENCV_LIBS/opencv/sources/modules/flann/include"
win32:INCLUDEPATH += "$$DIR_OPENCV_LIBS/opencv/sources/modules/features2d/include"
win32:INCLUDEPATH += "$$DIR_OPENCV_LIBS/opencv/sources/modules/calib3d/include"
win32:INCLUDEPATH += "$$DIR_OPENCV_LIBS/opencv/sources/modules/legacy/include"
win32:INCLUDEPATH += "$$DIR_OPENCV_LIBS/opencv/sources/modules/objdetect/include"
win32:INCLUDEPATH += "$$DIR_OPENCV_LIBS/opencv/sources/modules/highgui/include"
win32:INCLUDEPATH += "$$DIR_OPENCV_LIBS/opencv/sources/modules/photo/include"
win32:INCLUDEPATH += "$$DIR_OPENCV_LIBS/opencv/sources/modules/ml/include"
win32:INCLUDEPATH += "$$DIR_OPENCV_LIBS/opencv/sources/modules/contrib/include"
win32:INCLUDEPATH += "$$DIR_OPENCV_LIBS/opencv/sources/modules/hal/include"
win32:INCLUDEPATH += "$$DIR_OPENCV_LIBS/opencv/sources/modules/imgcodecs/include"
win32:INCLUDEPATH += "$$DIR_OPENCV_LIBS/opencv/sources/modules/videoio/include"

win32:LIBS += -L"$$DIR_OPENCV_LIBS/opencv/compilado/lib"

win32:LIBS += -lopencv_core310.dll
win32:LIBS += -lopencv_highgui310.dll
win32:LIBS += -lopencv_imgproc310.dll
win32:LIBS += -lopencv_objdetect310.dll
#win32:LIBS += -lopencv_calib3d310.dll
#win32:LIBS += -lopencv_ml310.dll
#win32:LIBS += -lopencv_features2d310.dll
#win32:LIBS += -lopencv_flann310.dll
#win32:LIBS += -lopencv_photo310.dll
#win32:LIBS += -lopencv_stitching310.dll
#win32:LIBS += -lopencv_superres310.dll
#win32:LIBS += -lopencv_video310.dll
#win32:LIBS += -lopencv_videostab310.dll
win32:LIBS += -lopencv_imgcodecs310.dll  # imread imwrite
win32:LIBS += -lopencv_videoio310.dll

SOURCES += \
    main.cpp \
    graph/graph.cpp \
    graph/node.cpp \
    graph/xmlreader.cpp \
    theme/colorizer.cpp \
    theme/theme.cpp \
    interface/block.cpp \
    interface/interface.cpp \
    processor/camera.cpp \
    interface/image.cpp \
    speech.cpp \
    interface/camerawidget.cpp

HEADERS += \
    graph/graph.hpp \
    graph/node.hpp \
    graph/xmlreader.hpp \
    theme/colorizer.hpp \
    theme/theme.hpp \
    interface/block.hpp \
    interface/interface.hpp \
    processor/camera.hpp \
    common.hpp \
    interface/image.hpp \
    speech.hpp \
    interface/camerawidget.h \
    interface/texture.h

FORMS += \
    interface/interface.ui \
    interface/block.ui
