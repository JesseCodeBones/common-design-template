#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main(){

    char passwd[8] = "pw";
    char in[8];



     printf("please input 8 charactors password \n");

    while (1)
    {
        scanf("%s", &in);
        if(strcmp(in, passwd) == 0) {
            printf("password is OK\n");
            break;
        } else {
            printf("passwd address 0x%x\n", &passwd);
            printf("input address 0x%x\n", &in);
            printf("incorrect password, please try again\n");
        }
    }



    return 0;
}