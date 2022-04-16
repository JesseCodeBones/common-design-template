#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

    int a[3] = {1,2,3}, b[4];

    memcpy(b,a,sizeof(a));

    int* index = b;

    for (size_t i = 0; i < 4; i++)
    {
        printf("%d\n", *index);
        index += 1;
    }

    return 0;
}