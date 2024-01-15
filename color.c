#include "fdf.h"

///// COLOR
//#include <inttypes.h>

// int encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
// {
// 	return (red << 16 | green << 8 | blue);
// }

/////////// IMPORT /////////////////////////////////////


int	gradient(int startcolor, int endcolor, int len, int i)
{
	double increment[3];
	int new[3];
	int newcolor;

	increment[0] = (double)((R(endcolor)) - (R(startcolor))) / (double)len;
    increment[1] = (double)((G(endcolor)) - (G(startcolor))) / (double)len;
    increment[2] = (double)((B(endcolor)) - (B(startcolor))) / (double)len;

    new[0] = (R(startcolor)) + round(i * increment[0]);
    new[1] = (G(startcolor)) + round(i * increment[1]);
    new[2] = (B(startcolor)) + round(i * increment[2]);

    newcolor = RGB(new[0], new[1], new[2]);

    return (newcolor);
}