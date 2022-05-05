#include <iostream>

using namespace std;

struct student
{
    int m_age;
    int m_number;
    string m_name;
    student *next;
};

student m_header = {0};

void addHeader(student *node){
    node->next = m_header.next;
    m_header.next = node;
}

void addFoot(student *node) {
    student *cursor = &m_header;
    while (cursor->next)
    {
        cursor = cursor->next;
    }
    cursor->next = node;
}

void loopLinkedList(void (*fun)(student*)){
    student *cursor = &m_header;
    while (cursor->next)
    {
        fun(cursor->next);
        cursor = cursor->next;
    }
}

void printStudent(student *s){
    cout<<s->m_number<<" "<<s->m_age<<" "<<s->m_name<<" "<<endl;
}

void freeStudent(student *s) {
    free(s);
}

int main(int, char**) {

    char opcode;

    while (1)
    {
        opcode = 'u';
        cout<<"input s for student input, q for quite"<<endl;
        cin>>opcode;
        if (opcode == 's')
        {
            int number;
            int age;
            string name = string();
            cout<<"input number"<<endl;
            cin>>number;
            cout<<"input age"<<endl;
            cin>>age;
            cout<<"input name"<<endl;
            cin>>name;
            cout<<"input end"<<endl;
            student *s = (student*) malloc(sizeof(student));
            s->m_age = age;
            s->m_name = name;
            s->m_number = number;
            addHeader(s);
        } else if (opcode == 'q'){
            loopLinkedList(printStudent);
            loopLinkedList(freeStudent);
            exit(0);
        } else {
            exit(1);
        }
        
    }

   return 0;
}
