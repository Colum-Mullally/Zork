#include "windowthreads.h"
#include "House.h"




windowThreads::windowThreads()
{
    m.show();

}

void windowThreads::run(){
  while(m.getOpen()){
      sleep(1);
            if(m.cWindow.getCraftChange()){
                m.cWindow.setFalse();
                m.fillList();
            }
    }
}
