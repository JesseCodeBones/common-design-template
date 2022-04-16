#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main(){
    int i = 0;
    justhere:
    i++;
    printf("value i = %d\n", i);
    if (i<10)
    {
        goto justhere;
    }
    printf("finished");

    return 0;
}