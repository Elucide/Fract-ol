/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:20:37 by yschecro          #+#    #+#             */
/*   Updated: 2022/04/11 14:30:33 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	julia(int rate, complex c)
{
	int		iter;
	complex	z;
	complex	temp;
	t_data	*data;

	data = _data();
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
	return (ft_maths(iter, z));
}

int	mandelbrot(int rate, complex c)
{
	int		iter;
	complex	z;
	complex	temp;
	t_data	*data;

	data = _data();
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
	return (ft_maths(iter, z));
}
//	return (rgb(iter, data->mode) + (z.real / sin(z.real) + fabs(z.img)));

int	burning_ship(int rate, complex c)
{
	int		iter;
	complex	z;
	complex	temp;
	t_data	*data;

	data = _data();
	z.real = 0;
	z.img = 0;
	iter = 0;
	while (squared_modulus(z) < 4 && iter < rate)
	{
		temp.real = (fabs(z.real) * fabs(z.real)) - (fabs(z.img) \
			* fabs(z.img)) + c.real;
		z.img = 2 * fabs(z.real) * fabs(z.img) + c.img;
		z.real = temp.real;
		iter++;
	}
	return (ft_maths(iter, z));
}

int	ft_maths(int iter, complex z)
{
	t_data	*d;
	int		m;

	d = _data();
	m = d->maths;
	if (d->maths == 0)
		return (rgb(iter, d->mode, m));
	if (d->maths == 1)
		return (rgb(iter, d->mode, m) + (z.real / sin(z.real) + fabs(z.img)));
	if (d->maths == 2)
		return (rgb(iter, d->mode, m) + log(z.img));
	if (d->maths == 3)
		return (rgb(iter, d->mode, m) - log(sin(z.real * z.img)));
	if (d->maths == 4)
		return (rgb(iter, d->mode + exp(z.real * z.img), m));
	if (d->maths == 5)
	{
		d->maths = 0;
		return (rgb(iter, d->mode, m));
	}
	return (0);
}

//return (rgb(iter, data->mode) + (z.real / sin(z.real) + fabs(z.img)));
//return (rgb(iter) + (z.real / sin(z.real) + fabs(z.img)));
//return (rgb(iter) - log(sin(z.real * z.img)));
//return (rgb(iter) - sin(z.real * z.img));
//return (rgb(iter) - sin(z.real * z.img));
