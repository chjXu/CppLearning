#include <iostream>

using namespace std;
/*
class News
{
private:
    /* data */
    /*
public:
    void header()
    {
        cout << "公共头部" << endl;
    }

    void footer()
    {
        cout << "公共底部" << endl;
    }

    void left()
    {
        cout << "左侧列表" << endl;
    }

    void content()
    {
        cout << "新闻播报" << endl;
    }
};

class Play
{
private:
    /* data */
    /*
public:
    void header()
    {
        cout << "公共头部" << endl;
    }

    void footer()
    {
        cout << "公共底部" << endl;
    }

    void left()
    {
        cout << "左侧列表" << endl;
    }

    void content()
    {
        cout << "拜拜和。。。" << endl;
    }
};
*/
//由于代码重复较多，采用继承的方法较好
//抽象一个基类的网页 重复代码写在网页上
class BasePage
{
public:
    void header()
    {
        cout << "公共头部" << endl;
    }

    void footer()
    {
        cout << "公共底部" << endl;
    }

    void left()
    {
        cout << "左侧列表" << endl;
    }
};

class News :public BasePage //继承
{
public:
    void content()
    {
        cout << "新闻播报" << endl;
    }
};

class Play :public BasePage //继承
{
public:    
    void content()
    {
        cout << "拜拜和。。。" << endl;
    }
};

class Game :public BasePage //继承
{
public:
    void content()
    {
        cout << "playing game" << endl;
    }
};

void test01()
{
    News news;
    news.header();
    news.footer();
    news.left();
    news.content();

    Play play;
    play.header();
    play.footer();
    play.left();
    play.content();
}

void test02()
{
    cout << "新闻网页内容" << endl;
    News news;
    news.header();
    news.footer();
    news.left();
    news.content();

    cout << "娱乐网页内容" << endl;
    Play play;
    play.header();
    play.footer();
    play.left();
    play.content();

    cout << "游戏网页内容" << endl;
    Game game;
    game.header();
    game.footer();
    game.left();
    game.content();
}

//BasePage 基类（父类） News派生类（子类）
//public 继承方式

int main()
{
    test01();
    test02();

    return 0;
}