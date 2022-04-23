#include <stdio.h>
#include <stdlib.h>


int main(){

    FILE *fp = fopen("helloJesse.text", "r");   
    char c;
    while (c = fgetc(fp)) 
    {
        if (c == EOF)
        {
            if (feof(fp) != 0)
            {
                printf("\nfinish reading\n");
                break;//normal end of file
            } else {
                if (ferror(fp) != 0)
                {
                    printf("error happened");
                    break;
                }
            }
        } else {
            printf("%c", c);
        }
        
    }
    


    return 0;
}