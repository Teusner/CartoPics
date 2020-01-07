#define BOOST_TEST_DYN_LINK 
#define BOOST_TEST_MODULE TestTriangle

#include <boost/test/unit_test.hpp>
#include <geometry/Triangle.hpp>
#include <geometry/Point.hpp>
#include <eigen3/Eigen/Dense>

BOOST_AUTO_TEST_CASE(TriangleInit) {
	Triangle T(0, 0, 0, 1, 0, 0, 0, 1, 0);
	BOOST_CHECK_CLOSE(T.z, 0.0, 0.001);
	BOOST_CHECK_CLOSE(T.n[0], 0.0, 0.001);
	BOOST_CHECK_CLOSE(T.n[1], 0.0, 0.001);
	BOOST_CHECK_CLOSE(T.n[2], 1.0, 0.001);
}