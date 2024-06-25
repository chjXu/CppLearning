#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    void show()
    {
        cout << "Person show" << endl;
    }

    void showAge()
    {
        if(this == NULL)
        {
            return;
        }
        cout << this->m_Age << endl;
    }

    int m_Age;
};

void test01()
{
    Person * p = NULL;
    p->show();
    p->showAge();
}


int main()
{
    test01();
    return 0;
}