#include <iostream>
#include <unistd.h>
#include <thread>
#include <stdlib.h>

using namespace std;

void f1(){
    cout << "hello" << endl;
}
void f2(){
    cout << "word" << endl;
}

int main(){
    thread t1(f1);
    t1.join();
    thread t2(f2);    
    t2.join();

    return 0;
}