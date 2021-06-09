#include <iostream>
using namespace std;
//设计立方体类，求出立方体体积和面积，分别用全局函数和成员函数判断两个立方体是否相等

class Cube
{
    public:
        //设置长
        void setL(int l)
        {
            x = l;
        }
        //得到长
        int getL()
        {
            return x;
        }

        //设置宽
        void setW(int w)
        {
            y = w;
        }
        //得到宽
        int getW()
        {
            return y;
        }

        //设置高
        void setH(int h)
        {
            z = h;
        }
        //得到高
        int getH()
        {
            return z;
        }

        void getCubeS()
        {
            int s = 2*x*y + 2*x*z + 2*y*z;
            cout << "The S is: " << s << endl;
        }

        void getCubeV()
        {
            int v = x*y*z;
            cout << "The V is: " << v << endl;
        }

    //通过成员函 数判断是否相等
    bool compareCubeClass(Cube &cub)
    {
        bool ret = x == cub.getL() && y == cub.getW() && z == cub.getH();
        return ret;
    }

    private:
        int x;//长
        int y;//宽
        int z;//高
};

//为什么const刚刚不能添加？没法保证成员函数里是否修改了成员属性
/*
void func(const Cube &cub)
{
    cub.getL();
}
*/

//全局函数判断 两个立方体是否相等
bool compareCube(Cube &cub1,Cube &cub2)
{
    if(cub1.getL() == cub2.getL() && cub1.getW() == cub2.getW() && cub1.getH() == cub2.getH())
    {
        return true;
    }
    else
    {
        return false;
    }

}

void test01()
{
    Cube c1;
    c1.setL(10);
    c1.setW(10);
    c1.setH(10);

    c1.getCubeS();
    c1.getCubeV();

    Cube c2;
    c2.setL(10);
    c2.setW(10);
    c2.setH(10);

    //通过全局
    bool ret = compareCube(c1,c2);
    if (ret)
    {
        cout << " c1 = c2" << endl;
    }
    else
    {
        cout << "c1 != c2" << endl;
    }
    //通过成员
    bool ret2 = c1.compareCubeClass(c2);
    if(ret2)
    {
        cout << "通过成员： c1 = c2" << endl;
    }
    else
    {
        cout << "通过成员： c1 != c2" << endl;
    }
    

}

int main()
{
    test01();
    return 0;
}