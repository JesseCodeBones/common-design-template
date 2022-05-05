#include <iostream>

// [return type] operator [operator name] ([parameters]){}
using namespace std;
class complex
{
private:
    int m_real, m_imaginary;
public:
    complex(int real, int imaginary):m_real(real), m_imaginary(imaginary){};
    ~complex();
    complex& operator + ( const complex& );
    string getDesc();
};


complex::~complex()
{
}

complex& complex::operator+(const complex& cpl) {
    m_real += cpl.m_real;
    m_imaginary += cpl.m_imaginary;
    return *this;
}

string complex::getDesc(){
    return "real:"+to_string(m_real)+" imaginary:"+to_string(m_imaginary);
}



int main(int, char**) {
    complex cpl1(1,2), cpl2(2,3);
    cpl1 = cpl1 + cpl2;
    std::cout << cpl1.getDesc();
}
