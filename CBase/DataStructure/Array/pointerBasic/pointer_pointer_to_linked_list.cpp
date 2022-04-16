#ifndef __pointer_pointer_to_linked_list__
#define __pointer_pointer_to_linked_list__
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct linked_list_t
{
    int data;
    struct linked_list_t *next;
}linked_list_t;


int main(void) {
    linked_list_t a, b, c;
    
    a.data = 1;
    b.data = 2;
    c.data = 3;
    c.next = NULL;
    a.next = &b;
    b.next = &c;

    //delete b
    linked_list_t *entry = &a;
    linked_list_t **pp = &entry;

    while (entry != NULL)
    {
        if (entry->data == 2)
        {
            *pp = entry->next;
        } else {
            pp = &entry->next;
        }
        entry = entry->next;
    }
    
    entry = &a;
    
    while (entry != NULL)
    {
        printf("%d\n", entry->data);
        entry = entry->next;
    }

    
}


#endif