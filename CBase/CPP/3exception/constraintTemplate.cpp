#include <iostream>
using namespace std;

template <class T, class B>
struct Derived_from
{
    static void constraints(T *p) { B *pb = p; }
    Derived_from() { void (*p)(T *) = constraints; }
};

class base_class
{
private:
    /* data */
public:
    base_class(/* args */);
    ~base_class();
};

base_class::base_class(/* args */)
{
}

base_class::~base_class()
{
}

class sub_class : public base_class
{
private:
    /* data */
public:
    sub_class(/* args */);
    ~sub_class();
};

sub_class::sub_class(/* args */)
{
}

sub_class::~sub_class()
{
}

template <class T>
void printT(T *t)
{
    Derived_from<T, base_class>();
}

struct B
{
    B() { cout << "hello world" << endl; }
};
struct D : B
{
};
struct C
{
};

int main(void)
{
    sub_class msub = sub_class();
    printT(&msub);
    return 0;
}