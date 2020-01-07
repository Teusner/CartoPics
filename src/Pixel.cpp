#include <Pixel.hpp>

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

/*! https://gist.github.com/fairlight1337/4935ae72bcbcc1ba5c72 */

/*! \brief Convert RGB to HSV color space
  
  Converts a given set of RGB values `r', `g', `b' into HSV
  coordinates. The input RGB values are in the range [0, 1], and the
  output HSV values are in the ranges h = [0, 360], and s, v = [0,
  1], respectively.
  
  \param fR Red component, used as input, range: [0, 1]
  \param fG Green component, used as input, range: [0, 1]
  \param fB Blue component, used as input, range: [0, 1]
  \param fH Hue component, used as output, range: [0, 360]
  \param fS Hue component, used as output, range: [0, 1]
  \param fV Hue component, used as output, range: [0, 1]
  
*/
void Pixel::RGBtoHSV(float &fR, float &fG, float &fB, float &fH, float &fS, float &fV) {
    float fCMax = max(max(fR, fG), fB);
    float fCMin = min(min(fR, fG), fB);
    float fDelta = fCMax - fCMin;
    
    if(fDelta > 0) {
        if(fCMax == fR) {
        fH = 60 * (fmod(((fG - fB) / fDelta), 6));
        } else if(fCMax == fG) {
        fH = 60 * (((fB - fR) / fDelta) + 2);
        } else if(fCMax == fB) {
        fH = 60 * (((fR - fG) / fDelta) + 4);
        }
        
        if(fCMax > 0) {
        fS = fDelta / fCMax;
        } else {
        fS = 0;
        }
        
        fV = fCMax;
    } else {
        fH = 0;
        fS = 0;
        fV = fCMax;
    }
    
    if(fH < 0) {
        fH = 360 + fH;
    }
}

/*! \brief Convert HSV to RGB color space
  
  Converts a given set of HSV values `h', `s', `v' into RGB
  coordinates. The output RGB values are in the range [0, 1], and
  the input HSV values are in the ranges h = [0, 360], and s, v =
  [0, 1], respectively.
  
  \param fR Red component, used as output, range: [0, 1]
  \param fG Green component, used as output, range: [0, 1]
  \param fB Blue component, used as output, range: [0, 1]
  \param fH Hue component, used as input, range: [0, 360]
  \param fS Hue component, used as input, range: [0, 1]
  \param fV Hue component, used as input, range: [0, 1]
  
*/

void Pixel::HSVtoRGB(float& fR, float& fG, float& fB, float& fH, float& fS, float& fV) {
    float fC = fV * fS; // Chroma
    float fHPrime = fmod(fH / 60.0, 6);
    float fX = fC * (1 - fabs(fmod(fHPrime, 2) - 1));
    float fM = fV - fC;
    
    if(0 <= fHPrime && fHPrime < 1) {
        fR = fC;
        fG = fX;
        fB = 0;
    } else if(1 <= fHPrime && fHPrime < 2) {
        fR = fX;
        fG = fC;
        fB = 0;
    } else if(2 <= fHPrime && fHPrime < 3) {
        fR = 0;
        fG = fC;
        fB = fX;
    } else if(3 <= fHPrime && fHPrime < 4) {
        fR = 0;
        fG = fX;
        fB = fC;
    } else if(4 <= fHPrime && fHPrime < 5) {
        fR = fX;
        fG = 0;
        fB = fC;
    } else if(5 <= fHPrime && fHPrime < 6) {
        fR = fC;
        fG = 0;
        fB = fX;
    } else {
        fR = 0;
        fG = 0;
        fB = 0;
    }
    
    fR += fM;
    fG += fM;
    fB += fM;
}

Pixel::Pixel() {
    m_R = 1.0;
    m_G = 1.0;
    m_B = 1.0;
    RGBtoHSV(m_R, m_G, m_B, m_H, m_S, m_V);
}

void Pixel::getRGB(float &R, float &G, float &B) {
    R = m_R;
    G = m_G;
    B = m_B;
}

void Pixel::getHSV(float &H, float &S, float &V) {
    H = m_H;
    S = m_S;
    V = m_V;
}

void Pixel::setRGB(float &R, float &G, float &B) {
    if (R >= 0.0 and R <= 1.0)
        m_R = R;
    else
        throw "Error ! Red channel is not in [0.0, 1.0]";

    if (G >= 0.0 and G <= 1.0)
        m_G = G;
    else
        throw "Error ! Green channel is not in [0.0, 1.0]";

    if (B >= 0.0 and B <= 1.0)
        m_B = B;
    else
        throw "Error ! Blue channel is not in [0.0, 1.0]";

    RGBtoHSV(m_R, m_G, m_B, m_H, m_S, m_V);    
}

void Pixel::setHSV(float &H, float &S, float &V) {
    if (H >= 0.0 and H <= 360.0)
        m_H = H;
    else
        throw "Error ! Hue channel is not in [0.0, 360.0]";

    if (S >= 0.0 and S <= 1.0)
        m_S = S;
    else
        throw "Error ! Saturation channel is not in [0.0, 1.0]";

    if (V >= 0.0 and V <= 1.0)
        m_V = V;
    else
        throw "Error ! Value channel is not in [0.0, 1.0]";

    HSVtoRGB(m_R, m_G, m_B, m_H, m_S, m_V);    
}

std::ostream& operator<<(std::ostream& stream, Pixel& P) {

    // Getting the RGB channels of the Pixel
    float R, G, B;
    P.getRGB(R, G, B);

    // Casting RGB to unsigned char
    unsigned char r = R*255;
    unsigned char g = G*255;
    unsigned char b = B*255;

    // Putting it in the stream
	stream << r << g << b;
	return stream;
}