#include "DEM.h"
#include "delaunator/delaunator.hpp"

using namespace std;

double projection(double &lati, double &longi, double &x, double &y) {
    const int rho = 6371000;
    x = rho*abs(longi)*cos(lati);
    y = rho*abs(lati);
}

struct Point {double x, y;};

bool isPointInTriangle(Point s, Point a, Point b, Point c) {
    int as_x = s.x-a.x;
    int as_y = s.y-a.y;

    bool s_ab = (b.x-a.x)*as_y-(b.y-a.y)*as_x > 0;

    if ((c.x-a.x)*as_y-(c.y-a.y)*as_x > 0 == s_ab) return false;
    if ((c.x-b.x)*(s.y-b.y)-(c.y-b.y)*(s.x-b.x) > 0 != s_ab) return false;

    return true;
}

DEM::DEM() {
    m_x = 100;
    m_y = 100;
}

DEM::DEM(int x, int y) : m_x(x), m_y(y) {}

DEM::~DEM() {}

void DEM::read(const string& filename) {
    ifstream f(filename);
    cout << "       \033[34mfilename = " << filename << "\033[0m" << endl;

	if (!f.is_open())
		cout << "An error occurred while opening the file" << filename << endl;
	
    else {
        for(std::string line; std::getline(f, line);) {
            // Make a stream for the line
            istringstream in(line);
            
            // Reading the coords
            double x, y, z;
            in >> x >> y >> z;

            double x_proj, y_proj;
            projection(x, y, x_proj, y_proj);
            
            // Raw data storage
            m_data_raw.insert(make_pair(make_pair(x_proj, y_proj), z));
        }

        // Statistics on the raw data
        cout << "[ 20%] \033[32mStatistics on the raw data\033[0m" << endl;

        Stats s_raw = statistics(m_data_raw);

        // Printing the statistics
        cout << "       \033[34mxmin = " << left << setw(15) << s_raw.xmin << " xmax = " << s_raw.xmax << endl;
        cout << "       ymin = " << left << setw(15) << s_raw.ymin << " ymax = " << s_raw.ymax << endl;
        cout << "       zmin = " << left << setw(15) << s_raw.zmin << " zmax = " << s_raw.zmax << "\033[00m" << endl;

        // Processing raw data and statistics        
        cout << "[ 25%] \033[32mStatistics on the processed data\033[0m" << endl;

        for (const auto &i : m_data_raw) {
            m_data.insert(make_pair(make_pair(i.first.first-s_raw.xmin, i.first.second-s_raw.ymin), i.second));
            m_coords.push_back(i.first.first-s_raw.xmin);
            m_coords.push_back(i.first.second-s_raw.ymin);
        }

        Stats s = statistics(m_data);

        // Printing de statistics
        m_x = s.xmax - s.xmin;
        m_y = s.ymax - s.ymin;

        cout << "       \033[34mm_x = " << left << setw(16) << m_x << " m_y = " << m_y << endl;
        cout << "       xmin = " << left << setw(15) << s.xmin << " xmax = " << s.xmax << endl;
        cout << "       ymin = " << left << setw(15) << s.ymin << " ymax = " << s.ymax << endl;
        cout << "       zmin = " << left << setw(15) << s.zmin << " zmax = " << s.zmax << "\033[00m" << endl;

        // Setting up the labelisator
        labelizator = min(m_x, m_y)/10;
    }
    f.close();
}

Stats DEM::statistics(map <pair<double, double>, double> m_map) {
    // min and max searching in data
    Stats s;
    s.xmin = m_map.begin()->first.first;
    s.xmax = xmin;
    s.ymin = m_map.begin()->first.second;
    s.ymax = ymin;
    s.zmin = m_map.begin()->second;
    s.zmax = zmin;

    // Iterating the m_data map for finding xmin xmax ymin ymax
    for (const auto &i : m_map) {
        double x = i.first.first;
        double y = i.first.second;
        double z = i.second;

        if (x < s.xmin)
            s.xmin = x;
        if (x > s.xmax)
           s.xmax = x;
        if (y < s.ymin)
            s.ymin = y;
        if (y > s.ymax)
           s.ymax = y;
        if (z < s.zmin)
            s.zmin = z;
        if (z > s.zmax)
           s.zmax = z;
    }
    return (s);
}

void DEM::triangulation(void) {
    // Triangulation of data
    delaunator::Delaunator d(m_coords);

    cout << "       \033[34mNumber of triangles = " << d.triangles.size()/6<< "\033[00m" << endl;
    cout << "[ 40%] \033[32mLabelisation\033[0m" << endl;

    // Labelisation of the triangles
    for(std::size_t i = 0; i < d.triangles.size(); i+=3) {
        // Getting triangle's points coordinates
        double xA = d.coords[2 * d.triangles[i]];
        double yA = d.coords[2 * d.triangles[i] + 1];
        double xB = d.coords[2 * d.triangles[i + 1]];
        double yB = d.coords[2 * d.triangles[i + 1] + 1];
        double xC = d.coords[2 * d.triangles[i + 2]];
        double yC = d.coords[2 * d.triangles[i + 2] + 1];
        
        // Choosing a label for each area
        int lxA = xA/labelizator;
        int lyA = yA/labelizator;
        int lxB = xB/labelizator;
        int lyB = yB/labelizator;
        int lxC = xC/labelizator;
        int lyC = yC/labelizator;

        auto labelA = std::make_pair(lxA, lyA);
        auto labelB = std::make_pair(lxB, lyB);
        auto labelC = std::make_pair(lxC, lyC);

        // Storage of labelized triangles
        Triangle tA{lxA, lyA, xA, yA, xB, yB, xC, yC};
        m_triangles.insert(pair<pair<int, int>, Triangle>(labelA, tA));

        // cout << lxA << " " << lyA << endl;

        if (labelA != labelB) {
            Triangle tB{lxB, lyB, xA, yA, xB, yB, xC, yC};
            m_triangles.insert(pair<pair<int, int>, Triangle>(labelB, tB));
        }

        if (labelA != labelC and labelB!=labelC) {
            Triangle tC{lxA, lyA, xA, yA, xB, yB, xC, yC};
            m_triangles.insert(pair<pair<int, int>, Triangle>(labelC, tC));
        }
    }
}

void DEM::process(void) {
    // Creating image and storing the associated pointer
    vector<vector<unsigned char> > *ptr_image = new vector<vector<unsigned char> >(m_x, vector<unsigned char>(m_y, 255));
    m_ptr_image = ptr_image;

    // Processing pixels of the image
    Point M, A, B, C;
    for (int i = 0; i < m_x; i++) {
        for (int j = 0; j < m_y; j++) {
            M.x = i;    // * alpha
            M.y = j;    // * alpha
            
            // Get triangles by label
            //cout << int(M.x/labelizator) << " " << int(M.y/labelizator) << endl;
            
            auto range = m_triangles.equal_range(make_pair(int(M.x/labelizator), int(M.y/labelizator)));
            for (auto k = range.first; k != range.second; k++) {
                pair<int, int> label = k->first;
                // cout << k->first.first << " " << k->first.second << endl;

                Triangle t = k->second;

                A = {t.xA, t.yA};
                B = {t.xB, t.yB};
                C = {t.xC, t.yC};

                if (isPointInTriangle(M, A, B, C)) {
                    // cout << i << " " << j << endl;
                    double zA = m_data[make_pair(t.xA, t.yA)];
                    double zB = m_data[make_pair(t.xB, t.yB)];
                    double zC = m_data[make_pair(t.xC, t.yC)];
                    (*ptr_image)[i][j] = char(255/3*pow((zA + zB + zC)/zmax, 10));
                    //cout << "Salut" << endl;
                }
            }
        }
    }
}

void DEM::save(string filename, int x, int y) {
    ofstream f(filename);

	if (!f.is_open())
		cout << "An error occurred while saving the file" << filename << endl;
	
    else {
        // Header
        f << "P2" << endl;
        f << "# Digital Terrain Model" << endl;
        f << m_y << " " << m_x << endl;
        f << "255" << endl;

        // File
        vector<vector<unsigned char>> image = *m_ptr_image;
        for (int i = 0; i < m_x; i++) {
            for (int j = 0; j < m_y; j++)
                f << int(image[i][j]) << " ";
            f << endl;
        }
    }
    f.close();
}