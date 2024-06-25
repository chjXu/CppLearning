#include "Point.hpp"
#include "Line.hpp"

int main()
{
    // point2 dim
    Point2i p21(1, 1);
    Point2f p22(1.0, 2.0);
    Point2f p23;
    p23.copyFrom(p21);
    Point2f p24(1.0, 3.0);
    std::cout << p21.x() << " " << p21.y() << std::endl;
    std::cout << p22.x() << " " << p22.y() << std::endl;
    std::cout << p23.x() << " " << p23.y() << std::endl;
    Point2f p25;
    p25 = p23 - p22;
    std::cout << p25.x() << " " << p25.y() << std::endl;
    std::cout << p25.isZero() << std::endl;

    // point3 dim
    Point3i p31(1, 1, 1);
    Point3f p32(1.0, 2.0, 3.0);
    Point3f p33;
    p33.copyFrom(p31);
    Point3f p34(1.0, 3.0, 5.0);
    std::cout << p31.x() << " " << p31.y() << " " << p31.z() << std::endl;
    std::cout << p32.x() << " " << p32.y() << " " << p31.z() << std::endl;
    std::cout << p33.x() << " " << p33.y() << " " << p31.z() << std::endl;
    Point3f p35;
    p35 = p33 - p32;
    std::cout << p35.x() << " " << p35.y() << " " << p35.z() << std::endl;
    std::cout << p35.isZero() << std::endl;

    // line
    Line2f l(p23, p22);
    std::cout << l.sp().x() << " " << l.sp().y() << std::endl;
    std::cout << l.ep().x() << " " << l.ep().y() << std::endl;
    std::cout << l.vd().x() << " " << l.vd().y() << std::endl;
    return 0;
}