/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:52:33 by yschecro          #+#    #+#             */
/*   Updated: 2022/03/21 15:33:37 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

/*
int	mandelbrot(int rate, complex c)
{
	complex	z;
	complex	temp;
	int		n;

	z.real = 0;
	z.img = 0;
	n = 0;
	while (n < rate)
	{
		temp.real = (c.real * c.real) - (c.img * c.img) + z.real;
		z.img = 2 * c.real * c.img + z.img;
		z.real = temp.real;
		if (squared_modulus(z) > 4)
		{
			break ;
		}
		dprintf(1, "not breaked\n");
		n++;
	}
//	dprintf(1, "%f\n", squared_modulus(z));
	//	dprintf(1, "n : %d\n", n);
	return (n * 100);
}
*/

int	rgb(int iter)
{
	double	r;
	double	g;
	double	b;
	int		color;

	r = sin(0.3 * (double)iter);
	g = sin(0.3 * (double)iter);
	b = sin(0.3 * (double)iter) * 127 + 128;
	color = ((int)(255.999 * r) << 16) + ((int)(255.999 * g) << 8) \
			+ ((int)(255.999 * b));
	return (color);
}

int	mandelbrot(int rate, complex c)
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
	return (rgb(iter));
}

void	screen(int(*f)(int, complex))
{
	complex	c;
	t_data *data;

	data = _data();
	data->x_min = 0;
	data->y_min = 0;
	data->y_max = data->h / 2;
	data->x_max = data->w / 2;
	c.real = -2;
	c.img =  -2;
	dprintf(1, "step = %f\n", data->step);
	dprintf(1, "x_max = %f      y_max = %f\n", c.img, c.real);
	while (data->x_min < data->h)
	{
		c.img = -2;
		data->y_min = 0;
		while (data->y_min < data->w)
		{
			img_pixel_put(data->x_min, data->y_min, f(20, c));
			c.img += data->step;
			data->y_min++;
		}
		data->x_min++;
		c.real += data->step;
	}
	dprintf(1, "x_max = %f      y_max = %f\n", c.img, c.real);
}	

t_data	*_data(void)
{
	static	t_data	data;
	return	(&data);
}

t_data	ft_data_init(int res, double min)
{
	t_data	*data;

	data = _data();
	data->h = res;
	data->w = res;
	data->x = -data->w / 2;
	data->y = -data->h / 2;
	data->x_min = -min;
	data->y_min = -min;
	data->step = 0.005;
	return (*data);
}

void	print_square(void)
{
	t_data	*data;

	data = _data();
	int x = 30;
	int y = 30;
	while (x < 500)
	{
		y = 30;
		while (y < 500)
		{
			img_pixel_put(x, y, 56000);
			y++;
		}
		x++;
	}
}

int	main(void)
{
	t_data	*data;

	data = _data();
	ft_data_init(720, 2);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w, data->h, "fract-ol");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, data->w, data->h);
	mlx_img_addr();
	screen(&mandelbrot);
	//	print_square();
	mlx_push_img();
	mlx_loop(data->mlx_ptr);
	printf("mandelbrot printed\n");
	return (free(data->mlx_ptr), free(data->win_ptr), 0);
}
