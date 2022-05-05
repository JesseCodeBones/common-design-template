#include <iostream>
using namespace std;

class Person
{
private:
    string m_name;
    string sayMyName(){
        return "I am a person, my name is " + m_name;
    }
public:
    Person(string name);
    ~Person();
    void printSayMyName(){
        std::cout << sayMyName()<<std::endl;
    }
};

Person::Person(string name):m_name(name)
{
}

Person::~Person()
{
}

class Young
{
private:
    /* data */
public:
    Young(/* args */);
    ~Young();
};

Young::Young(/* args */)
{
}

Young::~Young()
{
}



class Student:public Person, public Young
{
private:
    string m_lession;
public:
    Student(string name, string lession);
    void study();
    ~Student();
};

Student::Student(string name, string lession):Person(name),m_lession(lession)
{
}

Student::~Student()
{
}

void Student::study(){
    printSayMyName();
    cout<<"actually I am also a student, I am studying"<<endl;
}

int main(void){
    Student std("Jesse", "cpp");
    std.study();

    Person p = Student("Lisa", "English");
    p.printSayMyName();
    return 0;
}
