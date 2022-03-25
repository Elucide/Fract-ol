/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:20:37 by yschecro          #+#    #+#             */
/*   Updated: 2022/03/25 16:49:25 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	julia(int rate, complex c)
{
	int		iter;
	complex	z;
	complex	temp;

	z.real = -0.038088;
	z.img = 0.9754633;
	iter = 0;
	while (squared_modulus(z) < 4 && iter < rate)
	{
		temp.real = (z.real * z.real) - (z.img * z.img) + c.real;
		z.img = 2 * z.real * z.img + c.img;
		z.real = temp.real;
		iter++;
	}
	return (rgb(iter));
}

int mandelbrot(int rate, complex c)
{
	int		iter;
	complex	z;
	complex	temp;

	z.real = 0;
	z.img = 0;
	iter = 0;
	while (squared_modulus(z) < 4 && iter < rate)
	{
		temp.real = (z.real * z.real) - (z.img * z.img) + c.real;
		z.img = 2 * z.real * z.img + c.img;
		z.real = temp.real;
		iter++;
	}
	return (rgb(iter) - sin(z.real * z.img));
}

//return (rgb(iter) + (z.real / sin(z.real) + fabs(z.img)));
//return (rgb(iter) - log(sin(z.real * z.img)));
//return (rgb(iter) - sin(z.real * z.img));
