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

    // Structure for statistics on map processing
    struct Stats {double xmin, xmax, ymin, ymax, zmin, zmax;};

    /*!
    *  \brief statistics
    *
    *  Processing statistics on a map. Extracting xmin, xmax, ymin, ymax, zmin and zmax on an map of pairs. 
    * 
    *  \param m_map : map of pairs of double
    */
    Stats statistics(std::map <std::pair<double, double>, double> m_map);

    /*!
    *  \brief sign
    *
    *  Method used in isPointInTriangle. Determine the sign of a product
    * 
    *  \param P1_x : x coordinate of the first point
    *  \param P1_y : y coordinate of the first point
    *  \param P2_x : x coordinate of the second point
    *  \param P2_y : y coordinate of the second point
    *  \param P3_x : x coordinate of the third point
    *  \param P3_y : y coordinate of the third point
    */
    double sign (double P1x, double P1y, double P2x, double P2y, double P3x, double P3y);

    /*!
    *  \brief isPointInTriangle
    *
    *  Checking if a Point is in a Triangle for data processing in DEM.
    * 
    *  \param s : Point object
    *  \param T : Triangle object in which the Point should be.
    */
    bool isPointInTriangle(Point s, Triangle T);

    /*!
    *  \brief concave_hull
    *
    *  This method help us to process a concave hull to the Delaunay's triangulation data, which lead to create virtual triangles. Checking the restricted circle has a radius lower or equal at alpha.
    * 
    *  \param T : Triangle object in which the Point should be.
    *  \param alpha : critical radius
    */
    bool concave_hull(Triangle T, float alpha);

#endif // TOOLS_HPP