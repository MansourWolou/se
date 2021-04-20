#include <iostream>
#include <unistd.h>
#include <thread>
#include <stdlib.h>

using namespace std;

void f(int s){
    cout << "debut" << endl;
    sleep(s);
    cout << "fin" << endl;
}

int main(){
    int st = 5;
    thread t(f,st);
    t.join();// the main thread wait for t to finish

    return 0;
}