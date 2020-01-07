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

    /*! \class Pixel
    * \brief Pixel for image processing
    *
    *  This Pixel class let us set RGB and HSV values. You can use an array of Pixel to represent an image.
    */

    class Pixel {
        public :
            /*!
		    *  \brief Default constructor
		   	*
		    *  Constructor of the Pixel class.
            */
            Pixel();
            
            /*!
		    *  \brief RGB Setter
		   	*
		    *  Setter for the coordinates of the Point class. 
            * 
            *  \param R : newer R value for the Pixel
		    *  \param G : newer G value for the Pixel
            *  \param B : newer B value for the Pixel
		    */
            void setRGB(float &R, float &G, float &B);

            /*!
		    *  \brief HSV Setter
		   	*
		    *  Setter for the coordinates of the Point class. 
            * 
            *  \param H : newer H value for the Pixel
		    *  \param S : newer S value for the Pixel
            *  \param V : newer V value for the Pixel
		    */
            void setHSV(float &H, float &S, float &V);

            /*!
		    *  \brief RGB Getter
		   	*
		    *  Getter for the coordinates of the Point class. 
            * 
            *  \param R : getting the R value of the Pixel
		    *  \param G : getting the G value of the Pixel
            *  \param B : getting the B value of the Pixel
		    */
            void getRGB(float &R, float &G, float &B);

            /*!
		    *  \brief HSV Getter
		   	*
		    *  Getter for the coordinates of the Point class. 
            * 
            *  \param H : getting the H value of the Pixel
		    *  \param S : getting the S value of the Pixel
            *  \param V : getting the V value of the Pixel
		    */
            void getHSV(float &H, float &S, float &V);
            
            /*!
		    *  \brief Stream operator <<
		   	*
		    *  To serialize the Pixel and easily save it to a file
            *
		    */
            friend std::ostream& operator<<(std::ostream& stream, Pixel& c);

        private :

            // R, G, B values
            float m_R, m_G, m_B;

            // H, S, V values
            float m_H, m_S, m_V;

            // Method to convert RGB values to HSV
            void RGBtoHSV(float &fR, float &fG, float &fB, float &fH, float &fS, float &fV);
            
            // Method to convert HSV values to RGB
            void HSVtoRGB(float &fR, float &fG, float &fB, float &fH, float &fS, float &fV);
    };

#endif // PIXEL_HPP