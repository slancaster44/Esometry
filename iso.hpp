#ifndef ISO_H
#define ISO_H

#include <allegro5/allegro.h>

#include <vector>
using namespace std;

#define ColorPlane vector<uint8_t>

struct Point3d { int X; int Y; int Z; };
struct Point2d { int X; int Y; };

double Distance(Point3d p1, Point3d p2);
double Distance(Point2d p1, Point2d p2);

double angleAtP1(Point3d p1, Point3d p2, Point3d p3);
double angleAtP1(Point2d p1, Point2d p2, Point2d p3);

Point2d getIsoPoint(Point3d p);

class Triangle {
public:
    Triangle(Point3d p1, Point3d p2, Point3d p3);
    ~Triangle();

    void SetTexture(ColorPlane Reds, ColorPlane Greens, ColorPlane Blues, ColorPlane Alphas);
    
    ALLEGRO_BITMAP* GetBitmap();
    Point2d GetRenderLocation();

    //Returns true if the point is inside the isometric projection
    //of the triangle
    bool isPointInsideProjection(Point2d input);

    Point2d isoP1;
    Point2d isoP2;
    Point2d isoP3;
    
private:
    double area2d;
    double area3d;

    Point3d p3d1;
    Point3d p3d2;
    Point3d p3d3;

    double angle3d1;
    double angle3d2;
    double angle3d3;

    double isoAngle1;
    double isoAngle2;
    double isoAngle3;

    double side3dP1P2;
    double side3dP2P3;
    double side3dP3P1;

    double sideIsoP1P2;
    double sideIsoP2P3;
    double sideIsoP3P1;

    int bitmapHeight;
    int bitmapWidth;
    ALLEGRO_BITMAP* bitmap;
};

#endif