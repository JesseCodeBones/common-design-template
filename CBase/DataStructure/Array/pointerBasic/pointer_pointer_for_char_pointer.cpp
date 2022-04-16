#ifndef __pointer_pointer_for_char_pointer__
#define __pointer_pointer_for_char_pointer__

#include<iostream>
using namespace std;
int main(void) {
    char* a[] = {"jesse", "is", "a", "good man"};
    for (size_t i = 0; i < 4; i++)
    {
        printf("%s -> 0x%x\n", *(a+i),  *(a+i));
    }
    
}


#endif