#ifndef PIXEL_HPP
#define PIXEL_HPP

    /*!
		* \file Pixel.h
		* \brief Pixel class for Pixel processing in Digital Elevation model generating.
		* \author brateaqu
		* \version 1.0
	*/

    #include <iostream>
    #include <fstream>

    class Pixel {
        public :
            Pixel();

            void setRGB(float &R, float &G, float &B);
            void setHSV(float &H, float &S, float &V);
            void getRGB(float &R, float &G, float &B);
            void getHSV(float &H, float &S, float &V);

            friend std::ostream& operator<<(std::ostream& stream, Pixel& c);

        private :

            float m_R, m_G, m_B;
            float m_H, m_S, m_V;

            void RGBtoHSV(float &fR, float &fG, float &fB, float &fH, float &fS, float &fV);
            void HSVtoRGB(float &fR, float &fG, float &fB, float &fH, float &fS, float &fV);
    };

#endif // PIXEL_HPP