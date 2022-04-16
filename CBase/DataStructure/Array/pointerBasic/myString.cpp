#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

// struct __attribute__ ((__packed__)) myString
// {
//     char data1;
//     int data2;
// };

// struct test1 {  
//     char c;  
//     int i;  
// };  
  
void print(void *a){
    float *b = (float*)a;
    printf("%f\n", *b);
}

int main(void) {

    int a = 6;
    print(&a);
    return 0;
}