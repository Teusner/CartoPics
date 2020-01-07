#ifndef Triangle_HPP
#define Triangle_HPP

    /*!
		* \file Triangle.hpp
		* \brief Triangle class for Pixel processing in Digital Elevation Model generating.
		* \author brateaqu
		* \version 1.0
	*/

    #include <eigen3/Eigen/Dense>
    #include <geometry/Point.hpp>

    /*! \class Triangle
    * \brief Triangle for DEM
    *
    *  Triangle structure to process data during digital elevation model generating
    */

    class Triangle {
        public :
            /*!
		    *  \brief Constructor
		   	*
		    *  Constructor of the Triangle class.
            * 
            *  \param xA : x coordinate of the first point
            *  \param yA : y coordinate of the first point
            *  \param zA : x coordinate of the first point
            * 
            *  \param xB : x coordinate of the second point
            *  \param yB : y coordinate of the second point
            *  \param zB : x coordinate of the second point
            * 
            *  \param xC : x coordinate of the third point
            *  \param yC : y coordinate of the third point
            *  \param zC : x coordinate of the third point
            */
            Triangle(double xA, double yA, double zA, double xB, double yB, double zB, double xC, double yC, double zC);

            // Points of the triangle   
            Point A, B, C;

            // mean of the 3 z coordinates
            double z;

            // Normal vector at the triangle
            Eigen::Vector3d n;

        private :

            // Vector AB and AC
            Eigen::Vector3d u, v;

            // Method to normal vector processing
            void setNormal(void);
    };

#endif // Triangle_HPP