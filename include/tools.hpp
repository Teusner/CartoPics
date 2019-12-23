#ifndef TOOLS_HPP
#define TOOLS_HPP

    /*!
		* \file tools.hpp
		* \brief Tools for Digital Elevation model generating.
		* \author brateaqu
		* \version 1.0
	*/

    #include <map>
    #include <geometry/Triangle.hpp>
    #include <geometry/Point.hpp>

    // Structure for statistics
    struct Stats {double xmin, xmax, ymin, ymax, zmin, zmax;};

    // Functions
    Stats statistics(std::map <std::pair<double, double>, double> m_map);
    double sign (double P1x, double P1y, double P2x, double P2y, double P3x, double P3y);
    bool isPointInTriangle(Point s, Triangle T);
    bool concave_hull(Triangle T, float alpha);

#endif // TOOLS_HPP