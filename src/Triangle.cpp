#include <geometry/Triangle.hpp>
#include <geometry/Point.hpp>

#include <math.h>

Triangle::Triangle(double xA, double yA, double zA, double xB, double yB, double zB, double xC, double yC, double zC) {
    A.setCoords(xA, yA, zA);
    B.setCoords(xB, yB, zB);
    C.setCoords(xC, yC, zC);

    z = (zA + zB + zC)/3;

    u = {xB-xA, yB-yA, zB-zA};
    v = {xC-xA, yC-yA, zC-zA};
    setNormal();
}

void Triangle::setNormal(void) {
    n = u.cross(v);
    n.normalize();
}