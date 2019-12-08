#ifndef DEM_H
#define DEM_H
    #include <map>
    #include <vector>
    #include <iterator> 

    #include <iostream>
    #include <iomanip>
    #include <fstream>
    #include <sstream>

    #include <math.h>

    using namespace std;

    // Structure of a pixel
    struct RGB {
        uint8_t red, green, blue;
        RGB() {} 
        RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
    };

    // Structure for statistics
    struct Stats {double xmin, xmax, ymin, ymax, zmin, zmax;};


    // Multi_dict
    struct Triangle {
        int ix;     // x label, non-unique
        int iy;     // y label, non-unique
        // Triangle data
        double xA, yA, xB, yB, xC, yC;
        // TODO add mean of z...
    };

    class DEM {
        public :
            DEM();
            DEM(int x, int y);
            ~DEM();

            void read(const string& filename);
            Stats statistics(map <pair<double, double>, double> m_map);
            void triangulation(void);
            void process(void);
            void save(string filename, int x, int y);

            // Containers
            map <pair<double, double>, double> m_data_raw;
            map <pair<double, double>, double> m_data;
            multimap <pair<int, int>, Triangle> m_triangles;
            std::vector<double> m_coords;            
            vector<vector <unsigned char>> *m_ptr_image = nullptr;
   
            int m_x;
            int m_y;

            double xmin;
            double xmax;
            double ymin;
            double ymax;
            double zmin;
            double zmax;

            int labelizator;
    };

#endif // DEM_H