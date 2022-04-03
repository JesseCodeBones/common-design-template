#include <stdio.h>
#include <stdlib.h>

struct stu_t
{
    int num;
    char name[100];

} stu_t;

#define ARRAYLEN 5

int main(){


     //可free的数组
     int  *ptr2;
     ptr2 = (int *)malloc(ARRAYLEN * sizeof(int *));

     for (size_t i = 0; i < ARRAYLEN; i++)
     {
         int* pt;
         pt = ptr2 + i;
         *pt = i;
     }

     for (size_t i = 0; i < ARRAYLEN; i++)
     {
         int* pt;
         pt = ptr2 + i;
         printf("index %d, value %d\n", i, *pt);
     }


     free(ptr2);

    return 0;
}