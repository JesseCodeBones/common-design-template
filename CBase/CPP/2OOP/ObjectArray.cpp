#include <iostream>

using namespace std;

class test_class
{
private:
    char c;
    int i;
public:
    test_class(char c);
    ~test_class();
    char getChar();
};

test_class::test_class(char c):c(c)
{
}

test_class::~test_class()
{
}
char test_class::getChar(){
    return c;
}



int main(int argc, char* argv[]){
    for (size_t i = 0; i < argc; i++)
    {
        printf("arg->%s\n", argv[i]);
    }

    test_class classes[] = {
        test_class('a'), test_class('b')
    };

    test_class *ptr = &classes[0];
    ptr += 1;
    printf("next class value = %c \n", ptr->getChar());
    
    return 0;
}