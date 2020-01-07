#include <geometry/Point.hpp>

Point::Point() {
    m_x = 0.0;
    m_y = 0.0;
    m_z = 0.0;
}

Point::Point(double x, double y, double z) {
    m_x = x;
    m_y = y;
    m_z = z;
}

void Point::setCoords(double x, double y, double z) {
    m_x = x;
    m_y = y;
    m_z = z;
}