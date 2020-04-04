QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GUI/ganttchart.cpp \
    main.cpp \
    GUI/mainwindow.cpp \
    Core/Data_Structures/Circular_Linked_List/circular_linked_list.cpp \
    Core/Data_Structures/Circular_Linked_List/c_l_l_node.cpp \
    Core/Data_Structures/heap.cpp \
    Core/Factories/process_factory.cpp \
    Core/Factories/scheduler_factory.cpp \
    Core/Process/priority_process.cpp \
    Core/Process/process.cpp \
    Core/Schedulers/f_c_f_s.cpp \
#    Core/Schedulers/priority_nonpreemptive.cpp \
#    Core/Schedulers/priority_preemptive.cpp \
#    Core/Schedulers/round_robin.cpp \
    Core/Schedulers/scheduler.cpp \
#    Core/Schedulers/s_j_f_nonpreemptive.cpp \
#    Core/Schedulers/s_j_f_preemptive.cpp \

HEADERS += \
    GUI/ganttchart.h \
    GUI/mainwindow.h \
    Core/Data_Structures/Circular_Linked_List/circular_linked_list.h \
    Core/Data_Structures/Circular_Linked_List/c_l_l_node.h \
    Core/Data_Structures/heap.h \
    Core/Factories/process_factory.h \
    Core/Factories/scheduler_factory.h \
    Core/Process/priority_process.h \
    Core/Process/process.h \
    Core/Schedulers/f_c_f_s.h \
#    Core/Schedulers/priority_nonpreemptive.h \
#    Core/Schedulers/priority_preemptive.h \
#    Core/Schedulers/round_robin.h \
    Core/Schedulers/scheduler.h \
#    Core/Schedulers/s_j_f_nonpreemptive.h \
#    Core/Schedulers/s_j_f_preemptive.h \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
