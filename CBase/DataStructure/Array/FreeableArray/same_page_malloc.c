//https://stackoverflow.com/a/19019942

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef unsigned char u_int8;

typedef struct same_page_malloc
{
    u_int8 *startPtr;
    u_int8 *availablePtr;
    
} same_page_t;

void initBlock(same_page_t *block) {
    block->startPtr = (u_int8 *) calloc(8192, sizeof(u_int8));
    block->availablePtr = (u_int8 *) (((uintptr_t)block->startPtr+0x0FFF) & ~ (uintptr_t)0x0FFF);
}

void destroyBlock(same_page_t *block) {
    block->availablePtr = NULL;
    free(block->startPtr);
    block->startPtr = NULL;
}

int main(void){
    same_page_t block;
    initBlock(&block);
    printf("0x%x\n", block.availablePtr);
    destroyBlock(&block);
    return 0;
}