#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

typedef unsigned char uint_8;

int main(void) {

    uint_8 *byte = (uint_8 *) malloc(sizeof(uint_8));
    *byte = 0xfa;
    printf("%d\n", *byte);
    
    free(byte);

}
