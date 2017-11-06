#ifndef WINDOWTHREADS_H
#define WINDOWTHREADS_H
#include "mainwindow.h"
#include <QThread>


class windowThreads:public QThread
{
    Q_OBJECT
private:
    MainWindow m;
    //void* threadWork(void* ptr);
public:
    windowThreads();
    void* threadWork();
    void run();
};

#endif // WINDOWTHREADS_H

