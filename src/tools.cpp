#include <tools.hpp>

Stats statistics(std::map <std::pair<double, double>, double> m_map) {
    // min and max searching in data
    Stats s;
    s.xmin = m_map.begin()->first.first;
    s.xmax = s.xmin;
    s.ymin = m_map.begin()->first.second;
    s.ymax = s.ymin;
    s.zmin = m_map.begin()->second;
    s.zmax = s.zmin;

    // Iterating the m_data map for finding xmin xmax ymin ymax
    for (const auto &i : m_map) {
        if (i.first.first < s.xmin)
            s.xmin = i.first.first;
        if (i.first.first > s.xmax)
           s.xmax = i.first.first;
        if (i.first.second < s.ymin)
            s.ymin = i.first.second;
        if (i.first.second > s.ymax)
           s.ymax = i.first.second;
        if (i.second < s.zmin)
            s.zmin = i.second;
        if (i.second > s.zmax)
           s.zmax = i.second;
    }
    return s;
}

double sign (double P1x, double P1y, double P2x, double P2y, double P3x, double P3y) {
    return (P1x - P3x) * (P2y - P3y) - (P2x - P3x) * (P1y - P3y);
}

bool isPointInTriangle(Point s, Triangle T) {
    double d1 = sign(s.m_x, s.m_y, T.A.m_x, T.A.m_y, T.B.m_x, T.B.m_y);
	double d2 = sign(s.m_x, s.m_y, T.B.m_x, T.B.m_y, T.C.m_x, T.C.m_y);
	double d3 = sign(s.m_x, s.m_y, T.C.m_x, T.C.m_y, T.A.m_x, T.A.m_y);

	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

bool concave_hull(Triangle T, float alpha) {
    std::pair <float, float> ab(T.B.m_x - T.A.m_x, T.B.m_y - T.A.m_y);
    std::pair <float, float> bc(T.C.m_x - T.B.m_x, T.C.m_y - T.B.m_y);
    std::pair <float, float> ca(T.A.m_x - T.C.m_x, T.A.m_y - T.C.m_y);

    float a = sqrt(pow(ab.first, 2) + pow(ab.second, 2));
    float b = sqrt(pow(bc.first, 2) + pow(bc.second, 2));
    float c = sqrt(pow(ca.first, 2) + pow(ca.second, 2));

    float p = (a + b + c)/2;

    float sb = abs(ab.second*ca.first - ab.first*ca.second)/(c*a);
    float sc = abs(bc.second*ca.first - bc.first*ca.second)/(b*c);
    float sa = abs(ab.second*bc.first - ab.first*bc.second)/(a*b);

    float R = p/(sa+sb+sc);

    if (R > alpha)
        return (false);
    else
        return (true);
}