#include <stdio.h>
#include <stdlib.h>

struct str_1 {
    int a;
    char b;
};

typedef struct str_2{
    int a;
    char b;
} str_2_t;

void changeValue(str_2_t *t) {
    t->a = 999;
}

enum DAY{MON=1, TUE, WED, THU, FRI, SAT, SUN};

int main(){
    //define type 1
    str_2_t t1;

    //define type 2
    struct str_1 t2;

    //define type 3
    struct 
    {
        int a;
        char b;
    } t3;
    
    //call function and change value
    t1.a = 1;
    t1.b = 'a';
    changeValue(&t1);
    printf("%d\n", t1.a);

    //enum value
    enum DAY day = MON;
    printf("%d\n", day);
    if (day == MON)
    {
        printf("this is monday");
    }

    return 0;
}