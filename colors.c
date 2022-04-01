/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:24:44 by yschecro          #+#    #+#             */
/*   Updated: 2022/04/01 16:51:50 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	rgb(int iter, int mode)
{
	double	r;
	double	g;
	double	b;
	int		color;

	r = sin(0.3 * (double)iter);
	g = sin(0.3 * (double)iter);
	b = sin(0.3 * (double)iter);
	if (mode == 0)
	{
		b *= 127;
		g += rand() * 500;
	}
	if (mode == 1)
	{
		r += 127;
		b += rand() * 500;
	}
	if (mode == 2)
	{
		g *= 127;
		b += rand() * 50;
	}
	color = ((int)(255.999 * r) << 16) + ((int)(255.999 * g) << 8) \
			+ ((int)(255.999 * b));
	return (color);
}
