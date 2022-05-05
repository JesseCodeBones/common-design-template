#include <iostream>
using namespace std;

template<typename T>
T mymax(T a, T b){
    return a>b?a:b;
}

int main(void){
    mymax(1,2);
    int a=1,b=2;
    max(&a, &b);
    return 0;
}