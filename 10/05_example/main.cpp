#include <iostream>
using namespace std;
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <algorithm>

void printDeque(const deque<int> &d)    //const_iterator只读迭代器
{
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        //*it = 10000;
        cout << *it << " ";
    }
    cout << endl;
}

int averageScore(deque<int> &d)
{
    sort(d.begin(), d.end());
    cout << "排序" << endl;
    printDeque(d);
    cout << "删除最值" << endl;
    d.pop_back();
    d.pop_front();
    printDeque(d);

    int sum;
    for(deque<int>::iterator it = d.begin(); it != d.end(); it++)
    {
        sum += *it;
    }
    //cout << "My ave_score is: " << sum/d.size() << endl;
    return sum/d.size();
    
}

void test01()
{
    vector<string> person;
    person.push_back("A");
    person.push_back("B");
    person.push_back("C");
    person.push_back("D");
    person.push_back("E");
    for(vector<string>::iterator it = person.begin(); it != person.end(); it++)
    {
        cout << "I am: " << *it << endl;
        cout << "and my scores are: " << endl;
        
        deque<int> score;
        //score.resize(10);
        for(int i=0; i<10; i++)
        {
            score.push_back(rand()%100 + 1);
            //cout << score[i] << endl;
            //compare(score);
        }
        printDeque(score);
        int ave = averageScore(score);
        cout << "My ave_score is: " << ave  << "\n" << "\n "<< endl;
        
    }
}

/////////////////////////////////////////////////////////////////////////
class Person
{
public:
    Person(string name, int score)
    {
        this->m_Name = name;
        this->m_Score = score;
    }

    string m_Name;
    int m_Score;
};

void creatPersons(vector<Person>&v)
{
    string nameSeed = "ABCDE";
    for(int i=0; i<5; i++)
    {
        string name = "选手";
        name += nameSeed[i];

        int score = 0;
        Person p(name, score);
        v.push_back(p);
    }
}

void setScore(vector<Person>&v)
{
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        //cout << (*it).m_Name << endl;
        deque<int> d;
        for(int i=0; i<10; i++)
        {
            int score = (rand()%40 + 1) + 60;
            d.push_back(score);
        }
        //printDeque(d);

        sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();
        //printDeque(d);

        int sum = 0;
        for(deque<int>::iterator it = d.begin(); it != d.end(); it++)
        {
            sum += *it;
        }
        int avg = sum/d.size();
        

        it->m_Score = avg;
    }
}

void showScore(vector<Person>&v)
{
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << (*it).m_Name  << "平均分： " << it->m_Score << endl;
    }
}

void test02()
{
    vector<Person> v;

    creatPersons(v);
    /*
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it).m_Name << endl;
    }*/

    //打分
    setScore(v);

    showScore(v);
}

int main()
{
    //test01();

    test02();
 
    return 0;
}