#ifndef WINDOWTHREADS_H
#define WINDOWTHREADS_H
#include "mainwindow.h"


class windowThreads
{
private:
    MainWindow m;
    void* threadWork(void* ptr);
public:
    windowThreads();
};

#endif // WINDOWTHREADS_H
