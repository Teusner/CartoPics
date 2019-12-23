#ifndef POINT_H
#define POINT_H

    /*!
		* \file Point.h
		* \brief Point class.
		* \author brateaqu
		* \version 1.0
	*/

    class Point {
        public :
            Point();
            Point(double x, double y, double z);

            void setCoords(double x, double y, double z);
            double m_x, m_y, m_z;
    };

#endif // POINT_H