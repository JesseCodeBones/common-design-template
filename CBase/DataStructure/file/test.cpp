#include <stdio.h>
#include <stdlib.h>


int main(){
    int a = 0x000a0000;
    FILE *fp = fopen("data", "wb+");
    fwrite(&a, sizeof(int), 1, fp);
    return 0;
}