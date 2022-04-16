#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define STRHASHBUCKET_NUM  45634

unsigned hash(char* str) {

    unsigned int bucket = 0;
    while (*str != '\0')
    {
        bucket = (256*bucket+*str++) % STRHASHBUCKET_NUM;
    }

    return bucket;
}

int main(){

    char* myStr = "hello world1";
    unsigned hv = hash(myStr);
    printf("hash value is %d", hv);
    return 0;
}