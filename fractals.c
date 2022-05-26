/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:20:37 by yschecro          #+#    #+#             */
/*   Updated: 2022/05/25 18:58:39 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	julia(int rate, t_complex c)
{
	int			iter;
	t_complex	z;
	t_complex	temp;
	t_data		*data;

	data = _data();
	z.real = data->j.real;
	z.img = data->j.img;
	iter = 0;
	while (squared_modulus(z) < 4 && iter < rate)
	{
		temp.real = (z.real * z.real) - (z.img * z.img) + c.real;
		z.img = 2 * z.real * z.img + c.img;
		z.real = temp.real;
		iter++;
	}
	return (iter * 200);
}

int	mandelbrot(int rate, t_complex c)
{
	int			iter;
	t_complex	z;
	t_complex	temp;
	t_data		*data;

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
	return (iter * 200);
}
