#include <iostream>
#include <unistd.h>

using namespace std;

int main(){
    pid_t id1 = fork();
    if(id1 > 0){
      pid_t id2 = fork();
      if (id2 > 0){
        pid_t id3 = fork();
        if(id3 == 0){
            execlp("ps" , "ps" , "-l",NULL);
        }
      }else if (id2 == 0){
         execlp("ls" , "ls" , "-l", "." ,NULL);
      }
    }else if(id1 == 0){ 
        execlp("who" , "who" ,NULL);
    }
    
}