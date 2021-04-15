#include <iostream>
#include <unistd.h>

using namespace std;

int main(){
    int p = fork();
    if ( p > 0){
        int p2 = fork();
        if(p2 == 0){
            execlp("ps" , "ps" , "-l",NULL);
        }
    }else if ( p == 0){
        execlp("ls" , "ls" , "-l", "." ,NULL);
        }
}