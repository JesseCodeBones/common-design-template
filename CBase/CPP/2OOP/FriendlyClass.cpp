#include <iostream>
class Teacher
{
private:
    friend class Manager;
    int m_salary;
public:
    Teacher(int salary):m_salary(salary){};
    ~Teacher();
    std::string description();
};

class Manager
{
private:
    
    /* data */
public:
    Manager(/* args */);
    ~Manager();
    void adjustTeacherSalary(Teacher& t);
    
};

Manager::Manager(/* args */)
{
}

Manager::~Manager()
{
}
void Manager::adjustTeacherSalary(Teacher& t) {
    t.m_salary += 1;
}

Teacher::~Teacher()
{
}

std::string Teacher::description(){
    return "my salary is "+std::to_string(m_salary);
}

int main(void){
    Teacher t(12);
    Manager m1;
    m1.adjustTeacherSalary(t);
    std::cout<<t.description()<<std::endl;
    return 0;
}

