#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
int main(){
    errno = 0;
    sqrt(-1.0);
    printf("%d\n", errno);
    return 0;
}