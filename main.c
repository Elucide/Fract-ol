/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:52:33 by yschecro          #+#    #+#             */
/*   Updated: 2022/03/15 17:20:32 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"


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
			return (0);
		n++;
	}
	return (n);
}

void	screen(t_data data, int(*f)(int, complex))
{
	complex	c;

	data.y_max = data.h / 2;
	data.x_max = data.w / 2;
	c.real = data.x_min;
	c.img =  data.y_min;
	while (data.x < data.x_max)
	{
		c.img = data.y_min ;
		while (data.y < data.y_max)
		{
			if (f(20, c))	
				img_pixel_put(&data.img, data.x, data.y, 1489139);
			else
				img_pixel_put(&data.img, data.x, data.y, 10040319);
			c.img += data.step;
			data.y++;
		}
		data.x++;
		c.real += data.step;
	}
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
	data->step = data->x_min / data->h / 2;
	return (*data);
}

void	print_square(t_data data)
{
	int x = 30;
	int y = 30;
	while (x < 60)
	{
		y = 30;
		while (y < 60)
		{
			img_pixel_put(data.img.img_ptr, x, y, 560);
			y++;
		}
		x++;
	}
}

int	main(void)
{
	t_data	data;

	data = ft_data_init(720, 2);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.w, data.h, "fract-ol");
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, data.w, data.h);
	mlx_img_addr(data);
//	screen(data, &mandelbrot);
//	print_square();
	mlx_push_img(data);
	mlx_loop(data.mlx_ptr);
	printf("mandelbrot printed\n");
	return (free(data.mlx_ptr), free(data.win_ptr), 0);
}
