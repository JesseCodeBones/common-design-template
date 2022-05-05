#include "User.h"

string User::getName() const
{
    return this->name;
}

void User::setName(string nName) {
    this->name = nName;
}

User::~User()
{
}
