#include "Point.hpp"
#include "Line.hpp"

int main()
{
    // point
    Point2i p1(1, 1);
    Point2f p2(1.0, 2.0);
    Point2f p3;
    p3.copyFrom(p1);
    Point2f p4(1.0, 3.0);
    std::cout << p1.x() << " " << p1.y() << std::endl;
    std::cout << p2.x() << " " << p2.y() << std::endl;
    std::cout << p3.x() << " " << p3.y() << std::endl;

    Point2f p5;
    p5 = p3 - p2;
    std::cout << p5.x() << " " << p5.y() << std::endl;
    std::cout << p5.isZero() << std::endl;

    // line
    Line2f l(p3, p2);
    std::cout << l.sp().x() <<" " << l.sp().y() << std::endl;
    std::cout << l.ep().x() <<" " << l.ep().y() << std::endl;
    std::cout << l.vd().x() <<" " << l.vd().y() << std::endl;
    return 0;
}