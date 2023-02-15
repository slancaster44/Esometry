#include "context.hpp"
#include "iso.hpp"

int main() {
    Context c = Context();

    Point3d p1 = Point3d{256, 256, 256};
    Point3d p2 = Point3d{128, 256, 128};
    Point3d p3 = Point3d{256, 128, 128};
    Point3d p4 = Point3d{256, 128, 256};
    Point3d p5 = Point3d{128, 256, 256};
    Point3d p6 = Point3d{128, 128, 256};
    Point3d p7 = Point3d{128, 128, 128};

    Triangle* t1 = new Triangle(p6, p7, p2); //NO
    Triangle* t2 = new Triangle(p1, p5, p6); //NO
    Triangle* t3 = new Triangle(p1, p4, p6);
    Triangle* t4 = new Triangle(p5, p2, p6); //NO
    Triangle* t5 = new Triangle(p6, p7, p4);
    Triangle* t6 = new Triangle(p7, p4, p3);

    c.RegisterTriangle(t1);
    c.RegisterTriangle(t2);
    c.RegisterTriangle(t3);
    c.RegisterTriangle(t4);
    c.RegisterTriangle(t5);
    c.RegisterTriangle(t6);
    
    while (!c.shouldExit()) {
        c.RenderFrame();
    }
    return 0;
}