#include "windowthreads.h"
#include <pthread.h>




windowThreads::windowThreads()
{
    pthread_t t;
    int err = pthread_create(&t, NULL,(void*(*)(void*)) &windowThreads::threadWork, NULL);
    if(err){
        cout <<"error"<<endl;
    }
    m.show();
}

void *windowThreads::threadWork(void *ptr){


    pthread_exit(NULL);
}
