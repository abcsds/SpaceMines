QT += core gui phonon

TARGET = VRGame

HEADERS += \
    mainwindow.h \
    Calib/calibrator.h \
    Game/sprite.h \
    Game/gamewindow.h

SOURCES += \
    mainwindow.cpp \
    Calib/calibrator.cpp \
    main.cpp \
    Game/sprite.cpp \
    Game/gamewindow.cpp

FORMS += \
    mainwindow.ui \
    Calib/calibrator.ui \
    Game/gamewindow.ui

INCLUDEPATH += /opt/local/include \

LIBS += -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_flann

OTHER_FILES += \
    Game/sprite.png \
    Game/Pikes.png \
    Game/fire.gif \
    Game/sound/TANK9.mp3 \
    Game/sound/musical080.mp3 \
    Game/sound/musical001.mp3 \
    Game/sound/music.mp3 \
    Game/sound/exp.mp3

RESOURCES += \
    res.qrc
