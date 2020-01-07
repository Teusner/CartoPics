#define BOOST_TEST_DYN_LINK 
#define BOOST_TEST_MODULE TestPixel

#include <boost/test/unit_test.hpp>
#include <Pixel.hpp>

BOOST_AUTO_TEST_CASE(PixelInitRGB) {
	Pixel P;
	float R, G, B;
	P.getRGB(R, G, B);
	BOOST_CHECK_CLOSE(R, 1., 0.001);
	BOOST_CHECK_CLOSE(G, 1., 0.001);
	BOOST_CHECK_CLOSE(B, 1., 0.001);
}

BOOST_AUTO_TEST_CASE(PixelSetR) {
	Pixel P;
	float R = 0.8;
	float G = 1.0;
	float B = 1.0;
	P.setRGB(R, G, B);
	P.getRGB(R, G, B);
	BOOST_CHECK_CLOSE(R, 0.8, 0.001);
}

BOOST_AUTO_TEST_CASE(PixelSetG) {
	Pixel P;
	float R = 1.0;
	float G = 0.4;
	float B = 1.0;
	P.setRGB(R, G, B);
	P.getRGB(R, G, B);
	BOOST_CHECK_CLOSE(G, 0.4, 0.001);
}

BOOST_AUTO_TEST_CASE(PixelSetB) {
	Pixel P;
	float R = 1.0;
	float G = 1.0;
	float B = 0.6;
	P.setRGB(R, G, B);
	P.getRGB(R, G, B);
	BOOST_CHECK_CLOSE(B, 0.6, 0.001);
}