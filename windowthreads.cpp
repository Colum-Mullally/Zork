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
    int x = 0;
    while(x < 500000){
        x++;
        cout << x << endl;
    }

    pthread_exit(NULL);
}
