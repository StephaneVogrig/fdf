/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_efla.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 00:21:41 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/20 00:33:18 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// THE EXTREMELY FAST LINE ALGORITHM Variation C (Addition)
// inline void	myLine(t_img *img, int x, int y, int x2, int y2, t_pixel a, t_pixel b)
// {
// 	t_bool	yLonger = FALSE;
// 	int		incrementVal, endVal;
// 	int		shortLen=y2-y;
// 	int		longLen=x2-x;
// 	int		swap;
// 	double	decInc;
// 	double j = 0.0;
// 	t_gradiant	gradiant;

// 	gradiant = color_gradiant(a.color, b.color, vector2i_sub(b.vec2i, a.vec2i));
// 	if (abs(shortLen)>abs(longLen))
// 	{
// 		swap = shortLen;
// 		shortLen = longLen;
// 		longLen = swap;
// 		yLonger = TRUE;
// 	}

// 	endVal = longLen;
// 	if (longLen < 0)
// 	{
// 		incrementVal = -1;
// 		longLen = -longLen;
// 	}
// 	else
// 		incrementVal = 1;

// 	if (longLen == 0)
// 		decInc = (double)shortLen;
// 	else
// 		decInc = ((double)shortLen / (double)longLen);
// 	if (yLonger)
// 	{
// // ft_printf("a:%x b:%x", a.color, b.color);
// // ft_printf(" dx:%i dy:%i ", longLen, shortLen);
// // ft_printf("grad x:%f y:%f z:%f\n", gradiant.gradiant.x, gradiant.gradiant.y, gradiant.gradiant.z);
// 		for (int i=0;i!=endVal;i+=incrementVal)
// 		{
// 		if (a.color != b.color)
// // ft_printf("-- a:%x b:%x\n", a.color, b.color);
// 			a.color = color_gradiant_add(&gradiant);
// 			img_set_pixel(img, x + (int)j, y + i, a.color);
// 			j += decInc;
// 		}
// 	}
// 	else
// 	{
// 		for (int i=0;i!=endVal;i+=incrementVal)
// 		{
// 		if (a.color != b.color)
// 			a.color = color_gradiant_add(&gradiant);
// 			img_set_pixel(img, x + i, y + (int)j, a.color);
// 			j += decInc;
// 		}
// 	}
// }

// THE EXTREMELY FAST LINE ALGORITHM Variation E (Addition Fixed Point PreCalc)
inline void myLine(t_img *img, int x, int y, int x2, int y2, t_pixel a, t_pixel b) {
   	t_bool yLonger=FALSE;
	int shortLen=y2-y;
	int longLen=x2-x;
	t_gradiant	gradiant;

	gradiant = color_gradiant(a.color, b.color, vector2i_sub(b.vec2i, a.vec2i));
	if (ft_abs(shortLen)>ft_abs(longLen)) {
		int swap=shortLen;
		shortLen=longLen;
		longLen=swap;				
		yLonger=TRUE;
	}
	int decInc;
	if (longLen==0) decInc=0;
	else decInc = (shortLen << 16) / longLen;

	if (yLonger) {
		if (longLen>0) {
			longLen+=y;
			for (int j=0x8000+(x<<16);y<=longLen;++y) {
			if (a.color != b.color)
				a.color = color_gradiant_add(&gradiant);
				img_set_pixel(img, j >> 16, y, a.color);
				// myPixel(img,j >> 16,y);	
				j+=decInc;
			}
			return;
		}
		longLen+=y;
		for (int j=0x8000+(x<<16);y>=longLen;--y) {
			if (a.color != b.color)
				a.color = color_gradiant_add(&gradiant);
				img_set_pixel(img, j >> 16, y, a.color);
			// myPixel(img,j >> 16,y);	
			j-=decInc;
		}
		return;	
	}

	if (longLen>0) {
		longLen+=x;
		for (int j=0x8000+(y<<16);x<=longLen;++x) {
			if (a.color != b.color)
				a.color = color_gradiant_add(&gradiant);
				img_set_pixel(img, x, j >> 16, a.color);
			// myPixel(img,x,j >> 16);
			j+=decInc;
		}
		return;
	}
	longLen+=x;
	for (int j=0x8000+(y<<16);x>=longLen;--x) {
			if (a.color != b.color)
				a.color = color_gradiant_add(&gradiant);
				img_set_pixel(img, x, j >> 16, a.color);
		// myPixel(img,x,j >> 16);
		j-=decInc;
	}

}