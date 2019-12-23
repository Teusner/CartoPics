#ifndef Triangle_H
#define Triangle_H

    /*!
		* \file Triangle.hpp
		* \brief Triangle class for Pixel processing in Digital Elevation Model generating.
		* \author brateaqu
		* \version 1.0
	*/

    #include <eigen3/Eigen/Dense>
    #include <geometry/Point.hpp>

    class Triangle {
        public :
            Triangle(double xA, double yA, double zA, double xB, double yB, double zB, double xC, double yC, double zC);
                      
            Point A, B, C;
            double z;
            Eigen::Vector3d n;

        private :
            Eigen::Vector3d u, v;
            void setNormal(void);
    };

#endif // Triangle_H