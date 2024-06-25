#include <iostream>
using namespace std;
#include <string>
#include <stdexcept>

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        if(age < 0 || age > 200)
        {
            //throw out_of_range("age is out range");
            throw length_error("length is error");
        }

        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void test01()
{
    try
    {
        Person p("A",300);
    }
    catch(out_of_range &e)
    {
        cout << e.what() << endl;
    }
    catch(length_error &e)
    {
        cout << e.what() << endl;
    }
}

int main()
{
    test01();

    
    return 0;
}