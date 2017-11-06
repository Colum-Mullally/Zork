#include "windowthreads.h"




windowThreads::windowThreads()
{
    m.show();

}

void windowThreads::run(){
  while(m.getOpen()){
      sleep(1);
        if(m.getCraft()){
            if(m.cWindow.getCraftChange()){
                m.cWindow.setFalse();
                m.fillList();
                m.craftChange();
            }
        }
    }
}
