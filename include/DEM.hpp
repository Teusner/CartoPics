#ifndef DEM_HPP
#define DEM_HPP

    /*!
		* \file DEM.hpp
		* \brief DEM class for Digital Elevation model generating.
		* \author brateaqu
		* \version 1.0
	*/

    #include <math.h>
    #include <map>
    #include <vector>
    #include <iterator> 

    #include <iostream>
    #include <iomanip>
    #include <fstream>
    #include <sstream>

    #include <tools.hpp>
    #include <Pixel.hpp>
    #include <geometry/Triangle.hpp>
    #include <geometry/Point.hpp>

    using namespace std;

    /*! \class DEM
    * \brief Digital Elevation Model
    *
    *  Let us create an object to load a file of cartographics data, and processing
    *  it to get a coloured image as an output.
    */

    class DEM {
        public :
            /*!
		    *  \brief Constructor
		   	*
		    *  Constructor of the DEM class. It let us initialize the name of the input file,
            *  the name of the output file and the number of pixels for the x-axis of the output image.
		    */
            DEM(const string &ifname, const string &ofname, const int &x);

            /*!
		    *  \brief Destructor
		   	*
		    *  Destructor of the DEM class. Let us destruct the image dynamically allocated
            *  during the Digital Elevation Model processing.
		    */
            ~DEM();

            void read(const string& filename);
            void triangulation(void);
            void process(void);
            void hill_shading(void);
            void save(string filename, int x, int y);            

            // Statistics on the input file
            // TODO use Stats structure
            double xmin, xmax, ymin, ymax, zmin, zmax;

            float x_labelizator = 1;
            float y_labelizator = 1;

        private :

            //  Name of the input and output files
            string m_ifname, m_ofname;

            // Width and height of the output image
            int m_x, m_y;

            // The step between 2 Pixel in the data
            double m_step;

            // Maximum radius of triangles for concave hull
            float m_alpha = 0.8;
            
            // Fictive sun direction for hill shading
            Eigen::Vector3d m_sun = {-1/(std::sqrt(3)), 1/(std::sqrt(3)), 1/(std::sqrt(3))};

            // Map of pairs of coordinates for data storage
            std::map <std::pair<double, double>, double> m_data;

            // Vector of coordinates for Delaunay's triangulation
            std::vector<double> m_coords;

            // Map of pairs for triangles labelling
            std::map <std::pair<int, int>, std::vector<Triangle>> m_triangles;

            // Output image
            std::vector<std::vector<Pixel *>> m_image;
    };

#endif // DEM_HPP