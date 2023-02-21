#include <math.h>
#include <iostream>
using namespace std;

#include "iso.hpp"

Point2d getIsoPoint(Point3d p) {
    Point2d retVal;
    retVal.X = p.X - (p.Z / 4.0);
    retVal.Y = p.Y + (p.Z / 2.0);

    return retVal;
}

double Distance(Point3d p1, Point3d p2) {
    double a_squared = pow(float(p1.X - p2.X), 2.0);
    double b_squared = pow(float(p1.Y - p2.Y), 2.0);
    double d_squared = pow(float(p1.Z - p2.Z), 2.0);

    return sqrt(a_squared + b_squared + d_squared); 
}

double Distance(Point2d p1, Point2d p2) {
    double a_squared = pow(float(p1.X - p2.X), 2.0);
    double b_squared = pow(float(p1.Y - p2.Y), 2.0);

    return sqrt(a_squared + b_squared); 
}


double angleAtP1(Point2d p1, Point2d p2, Point2d p3) {
    double side3dP1P2 = Distance(p1, p2);
    double side3dP2P3 = Distance(p2, p3);
    double side3dP3P1 = Distance(p3, p1);

    double v1 = pow(side3dP3P1, 2.0) + 
        pow(side3dP1P2, 2.0) - pow(side3dP2P3, 2.0);
    
    double v2 = 2 * (side3dP3P1) * side3dP1P2;

    return acos(v1 / v2);
}

double angleAtP2(Point2d p1, Point2d p2, Point2d p3) {
    double side3dP1P2 = Distance(p1, p2);
    double side3dP2P3 = Distance(p2, p3);
    double side3dP3P1 = Distance(p3, p1);

    double v1 = pow(side3dP1P2, 2.0) + 
        pow(side3dP2P3, 2.0) - pow(side3dP3P1, 2.0);
    double v2 = 2 * side3dP1P2 * side3dP2P3;

    return acos(v1 / v2);
}

double angleAtP3(Point2d p1, Point2d p2, Point2d p3) {
    double side3dP1P2 = Distance(p1, p2);
    double side3dP2P3 = Distance(p2, p3);
    double side3dP3P1 = Distance(p3, p1);

    double v1 = pow(side3dP2P3, 2.0) + 
        pow(side3dP3P1, 2.0) - pow(side3dP1P2, 2.0);
    double v2 = 2 * side3dP3P1 * side3dP2P3;

    return acos(v1 / v2);
}

double angleAtP1(Point3d p1, Point3d p2, Point3d p3) {
    double side3dP1P2 = Distance(p1, p2);
    double side3dP2P3 = Distance(p2, p3);
    double side3dP3P1 = Distance(p3, p1);

    double v1 = pow(side3dP3P1, 2.0) + 
        pow(side3dP1P2, 2.0) - pow(side3dP2P3, 2.0);
    
    double v2 = 2 * (side3dP3P1) * side3dP1P2;

    return acos(v1 / v2);
}

double angleAtP2(Point3d p1, Point3d p2, Point3d p3) {
    double side3dP1P2 = Distance(p1, p2);
    double side3dP2P3 = Distance(p2, p3);
    double side3dP3P1 = Distance(p3, p1);

    double v1 = pow(side3dP1P2, 2.0) + 
        pow(side3dP2P3, 2.0) - pow(side3dP3P1, 2.0);
    double v2 = 2 * side3dP1P2 * side3dP2P3;

    return acos(v1 / v2);
}

double angleAtP3(Point3d p1, Point3d p2, Point3d p3) {
    double side3dP1P2 = Distance(p1, p2);
    double side3dP2P3 = Distance(p2, p3);
    double side3dP3P1 = Distance(p3, p1);

    double v1 = pow(side3dP2P3, 2.0) + 
        pow(side3dP3P1, 2.0) - pow(side3dP1P2, 2.0);
    double v2 = 2 * side3dP3P1 * side3dP2P3;

    return acos(v1 / v2);
}

Triangle::Triangle(Point3d p1, Point3d p2, Point3d p3) {
    p3d1 = p1;
    p3d2 = p2;
    p3d3 = p3;

    side3dP1P2 = Distance(p3d1, p3d2);
    side3dP2P3 = Distance(p3d2, p3d3);
    side3dP3P1 = Distance(p3d3, p3d1);

    angle3d1 = angleAtP1(p3d1, p3d2, p3d3);
    angle3d2 = angleAtP2(p3d1, p3d2, p3d3);
    angle3d3 = angleAtP3(p3d1, p3d2, p3d3);

    area3d = 0.5 * (side3dP3P1) * (sin(angle3d1) * (side3dP1P2));
    
    isoP1 = getIsoPoint(p1);
    isoP2 = getIsoPoint(p2);
    isoP3 = getIsoPoint(p3);

    cout << isoP1.X << ", " << isoP1.Y << "; ";
    cout << isoP2.X << ", " << isoP2.Y << "; ";
    cout << isoP3.X << ", " << isoP3.Y << "; " << endl;

    sideIsoP1P2 = Distance(isoP1, isoP2);
    sideIsoP2P3 = Distance(isoP2, isoP3);
    sideIsoP3P1 = Distance(isoP3, isoP1);

    isoAngle1 = angleAtP1(isoP1, isoP2, isoP3);
    isoAngle2 = angleAtP2(isoP1, isoP2, isoP3);
    isoAngle3 = angleAtP3(isoP1, isoP2, isoP3);

    area2d = 0.5 * (sideIsoP3P1) * (sin(isoAngle1) * (sideIsoP1P2));

    bitmapWidth = max(max(isoP1.X, isoP2.X), isoP3.X) - min(min(isoP1.X, isoP2.X), isoP3.X);
    bitmapHeight = max(max(isoP1.Y, isoP2.Y), isoP3.Y) - min(min(isoP1.Y, isoP2.Y), isoP3.Y);
    bitmap = al_create_bitmap(bitmapWidth, bitmapHeight);


void Triangle::SetTexture(ColorPlane Reds, ColorPlane Greens, ColorPlane Blues, ColorPlane Alphas) {
    
}

Point2d Triangle::GetRenderLocation() {
    int x = min(isoP1.X, min(isoP2.X, isoP3.X));
    int y = min(isoP1.Y, min(isoP2.Y, isoP3.Y));

    return Point2d {x,y};
}

ALLEGRO_BITMAP* Triangle::GetBitmap() {
    return bitmap;
}

Triangle::~Triangle() {
    al_destroy_bitmap(bitmap);
}

/* This is the edge function. It will return a negative value
 * if IN is one onside of line[P1, P2] and a positive value if
 * it is on the other side
 */
#define EF(V0, V1, P) \
    (P.X - V0.X) * (V1.Y - V0.Y) - (P.Y - V0.Y) * (V1.X - V0.X)

#define ARE_SAME_DIRECTIONS(D1, D2) \
    ((D1 >= 0 && D2 >= 0) || (D1 <= 0 && D2 <= 0))

bool Triangle::isPointInsideProjection(Point2d input) {
    float directionFromP1P2 = EF(isoP1, isoP2, input);
    float directionFromP1P2OfP3 = EF(isoP1, isoP2, isoP3);

    if (!ARE_SAME_DIRECTIONS(directionFromP1P2, directionFromP1P2OfP3)) {
        return false;
    }

    float directionFromP2P3 = EF(isoP2, isoP3, input);
    float directionFromP3P2OfP1 = EF(isoP2, isoP3, isoP1);

    if (!ARE_SAME_DIRECTIONS(directionFromP2P3, directionFromP3P2OfP1)) {
        return false;
    }

    float directionFromP3P1 = EF(isoP1, isoP3, input);
    float directionFromP3P1OfP2 = EF(isoP1, isoP3, isoP2);

    return ARE_SAME_DIRECTIONS(directionFromP3P1, directionFromP3P1OfP2);
}