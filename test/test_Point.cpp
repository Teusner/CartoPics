#define BOOST_TEST_DYN_LINK 
#define BOOST_TEST_MODULE TestPoint

#include <boost/test/unit_test.hpp>
#include <geometry/Point.hpp>
#include <math.h>

BOOST_AUTO_TEST_CASE(PointInit) {
	Point P;
	BOOST_CHECK_CLOSE(P.m_x, 0.0, 0.001);
	BOOST_CHECK_CLOSE(P.m_y, 0.0, 0.001);
	BOOST_CHECK_CLOSE(P.m_z, 0.0, 0.001);
}

BOOST_AUTO_TEST_CASE(PointInitParams) {
	double x = 5.0;
	double y = -2.0;
	double z = M_PI;
	Point P(x, y, z);
	BOOST_CHECK_CLOSE(P.m_x, 5.0, 0.001);
	BOOST_CHECK_CLOSE(P.m_y, -2.0, 0.001);
	BOOST_CHECK_CLOSE(P.m_z, M_PI, 0.001);
}

BOOST_AUTO_TEST_CASE(PointSetCoords) {
	Point P;
	double x = 1.0;
	double y = 2.0;
	double z = 3.0;
	P.setCoords(x, y, z);
	BOOST_CHECK_CLOSE(P.m_x, x, 0.001);
	BOOST_CHECK_CLOSE(P.m_y, y, 0.001);
	BOOST_CHECK_CLOSE(P.m_z, z, 0.001);
}