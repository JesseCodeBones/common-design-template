#include <stdio.h>
#include <stdlib.h>

typedef unsigned char u_int8;

typedef struct customerize_memory_block
{
    int size;
    u_int8 *start_pointer;
} customer_block_t;

void initBlock(customer_block_t *block){
    block->start_pointer = calloc(block->size, (sizeof(u_int8)));
}

void destroyContent(customer_block_t *block) {
    block->size = 0;
    free(block->start_pointer);
    block->start_pointer = NULL;
}


int main(){

    customer_block_t t1;
    t1.size = 24;
    initBlock(&t1);


    *(t1.start_pointer + 20) = 10;
    for (size_t i = 0; i < 24; i++)
    {
        printf("%d\n", *(t1.start_pointer + i));
    }
    destroyContent(&t1);

    return 0;
}