#ifndef __car__
#define __car__
#include <iostream>
#include <string>
#include "User.h"
using namespace std;

class car
{
private:
     User& m_user;
    string m_name;    
public:
    
    car(const car& source);
    car(const string name, User& user):m_name(name), m_user(user){}
    User& getUser(){return m_user;}
    ~car();
};
#endif
