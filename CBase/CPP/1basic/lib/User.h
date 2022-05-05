#ifndef __user__
#define __user__

#include <string>
#include <iostream>

using namespace std;

class User
{
private:
    string name;
public:
    User(string name):name(name){};
     string  getName() const ;
     void setName(string nName);
    ~User();
};
#endif


