/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:27:07 by yschecro          #+#    #+#             */
/*   Updated: 2022/04/01 16:36:40 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	screen(int (*f)(int, complex))
{
	complex	c;
	t_data	*data;

	data = _data();
	c.real = data->x_min;
	c.img = data->y_min;
	data->x = 0;
	data->y = 0;
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

int	render(float len, float o_x, float o_y)
{
	t_data	*data;

	data = _data();
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, data->w, data->h);
	mlx_img_addr();
	data->len = len;
	data->origin.real = o_x;
	data->origin.img = o_y;
	data->x_min = data->origin.real - data->len / 2;
	data->y_min = data->origin.img - data->len / 2;
	data->step = data->len / data->res;
	screen(data->f);
	mlx_push_img();
	return (1);
}
