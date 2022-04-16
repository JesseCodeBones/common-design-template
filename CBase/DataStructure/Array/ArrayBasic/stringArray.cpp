#include <stdio.h>
#include <stdlib.h>



int main(){

    char *a[2];
    char *s1 = (char *)"hello";
    char *s2 = (char *)"world";

    a[0] = s1;
    a[1] = s2;

    for (size_t i = 0; i < 2; i++)
    {
        printf(a[i]);
    }
    

    return 0;
}