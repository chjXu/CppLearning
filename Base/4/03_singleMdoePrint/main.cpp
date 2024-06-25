#include <iostream>
#include <string>
using namespace std;

class Printer
{
private:
//1.
    Printer(){count = 0;}
    Printer(const Printer& p);
private:
//2.
    static Printer* singlePrinter;
    int count;
public:
//4.
    static Printer* getInstance()
    {
        return singlePrinter;
    }
    void printText(string text)
    {
        cout << text << endl;
        count++;
        cout << count << endl;
    }
};
//3.
Printer* Printer::singlePrinter = new Printer;

void test01()
{
    //拿到打印机
    Printer * printer = Printer::getInstance();
    
    printer->printText("离职报告");
}
int main()
{
    test01();
    return 0;
}