#include <iostream>
using namespace std;
#include <string>
//编译不了啊
/*
main.cpp:15:26: error: looser throw specifier for ‘virtual const char* MyOutofRangeException::what() const’
     virtual const char * what() const
                          ^
In file included from /usr/include/c++/5/ios:39:0,
                 from /usr/include/c++/5/ostream:38,
                 from /usr/include/c++/5/iostream:39,
                 from main.cpp:1:
/usr/include/c++/5/exception:68:25: error:   overriding ‘virtual const char* std::exception::what() const throw ()’
     virtual const char* what() const _GLIBCXX_USE_NOEXCEPT;
                         ^
main.cpp:6:7: error: looser throw specifier for ‘virtual MyOutofRangeException::~MyOutofRangeException()’
 class MyOutofRangeException:public exception
       ^
In file included from /usr/include/c++/5/ios:39:0,
                 from /usr/include/c++/5/ostream:38,
                 from /usr/include/c++/5/iostream:39,
                 from main.cpp:1:
/usr/include/c++/5/exception:64:13: error:   overriding ‘virtual std::exception::~exception() throw ()’
     virtual ~exception() _GLIBCXX_USE_NOEXCEPT;
*/

class MyOutofRangeException:public exception
{
public:
    MyOutofRangeException(string errorInfo)
    {
        this->m_ErrorInfo = errorInfo;
    }

    virtual ~MyOutofRangeException(){}
    virtual const char * what() const
    {
        //return
        //string to char*    .c_str
        return this->m_ErrorInfo.c_str();
    }

    string m_ErrorInfo;
};


class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        if(age < 0 || age > 200)
        {
            throw MyOutofRangeException(string("Age is out"));

        }
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
    catch(MyOutofRangeException &e)
    {
        cout << e.what() << endl;
    }

}

int main()
{
    test01();

    
    return 0;
}
