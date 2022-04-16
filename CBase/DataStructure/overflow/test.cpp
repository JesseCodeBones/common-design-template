#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>


int safeAdd(int a, int b) {
    if (a>INT_MAX - b)
    {
        fprintf(stderr, "there is int overflow for add function with parameter %d, %d", a, b);
        exit(1);
    }
    return a+b;
}


int main(void){

    int a = INT_MAX - 10;
    int b = 12;
    int c = safeAdd(a, b);
    printf("result = %d", c);
    return 0;
}