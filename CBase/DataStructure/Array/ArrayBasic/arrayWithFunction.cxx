#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void changeValue(int a[]) {
    a[0] = 100;
}

int main(){
    int arr[] = {1,2,3};
    changeValue(arr);
    for (size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}