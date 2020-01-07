#ifndef POINT_HPP
#define POINT_HPP

    /*!
		* \file Point.hpp
		* \brief Point class.
		* \author brateaqu
		* \version 1.0
	*/

    /*! \class Point
    * \brief Point representing for DEM
    *
    *  Let us create a Point object to facilitate data manipulation
    */

    class Point {
        public :
            /*!
		    *  \brief Default Constructor
		   	*
		    *  Default constructor of the Point class. Each coordinate is
            *  set at 0.0.
		    */
            Point();

            /*!
		    *  \brief Constructor
		   	*
		    *  Constructor of the Point class. 
            * 
            *  \param x : x coordinate of the Point
		    *  \param y : y coordinate of the Point
            *  \param z : z coordinate of the Point
		    */
            Point(double x, double y, double z);

            /*!
		    *  \brief Coords Setter
		   	*
		    *  Setter for the coordinates of the Point class. 
            * 
            *  \param x : newer x coordinate of the Point
		    *  \param y : newer y coordinate of the Point
            *  \param z : newer z coordinate of the Point
		    */
            void setCoords(double x, double y, double z);

            // Coordinates of the point
            double m_x, m_y, m_z;
    };

#endif // POINT_HPP