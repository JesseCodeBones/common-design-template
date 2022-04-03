#include <stdio.h>
#include <stdlib.h>

struct stu_t
{
    int num;
    char name[100];

} stu_t;

#define ARRAYLEN 5

int main(){

     int a[] = {1,2,3,4,5};
     int* pa0 = &a[0];
     pa0 += 1;

     printf("pt size = 0x%x \n", &a);
     printf("second value = %d \n", *pa0);
     printf("array size = %d \n", sizeof(a));
     printf("array length = %d \n", sizeof(a)/sizeof(a[0]));

    return 0;
}