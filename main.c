/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:52:33 by yschecro          #+#    #+#             */
/*   Updated: 2022/03/22 16:40:41 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	screen(int (*f)(int, complex))
{
	complex	c;
	t_data	*data;

	data = _data();
	data->y_max = data->h / 2;
	data->x_max = data->w / 2;
	c.real = data->x_min;
	c.img = data->y_min;
	while (data->x < data->h)
	{
		c.img = data->y_min;
		data->y = 0;
		while (data->y < data->w)
		{
			img_pixel_put(data->x, data->y, f(50, c));
			c.img += data->step;
			data->y++;
		}
		data->x++;
		c.real += data->step;
	}
}

t_data	*_data(void)
{
	static t_data	data;

	return (&data);
}

t_data	ft_data_init(int res)
{
	t_data	*data;

	data = _data();
	data->h = res;
	data->w = res;
	data->x = 0;
	data->y = 0;
	data->len = 0.2;
	data->origin.real = -1;
	data->origin.img = 0.35;
	data->x_min = data->origin.real - data->len / 2;
	data->y_min = data->origin.img - data->len / 2;
	data->step = data->len / res;
	return (*data);
}

void	ft_free(void)
{
	t_data *data;

	data = _data();
	free(data->mlx_ptr);
	free(data->win_ptr);
	free(data->img.img_ptr);
}

int	main(void)
{
	t_data	*data;

	data = _data();
	ft_data_init(1080);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w, data->h, "fract-ol");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, data->w, data->h);
	mlx_img_addr();
	screen(&mandelbrot);
	mlx_push_img();
	mlx_loop(data->mlx_ptr);
	printf("mandelbrot printed\n");
	return (ft_free(), 0);
}
