/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:52:33 by yschecro          #+#    #+#             */
/*   Updated: 2022/03/25 17:00:11 by yschecro         ###   ########.fr       */
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

t_data	*_data(void)
{
	static t_data	data;

	return (&data);
}

t_data	ft_data_init(int res)
{
	t_data	*data;

	data = _data();
	data->res = 500;
	data->h = res;
	data->w = res;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w, data->h, "fract-ol");
	return (*data);
}

//0.25   r = 0.25  i=0

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
	screen(&mandelbrot);
	mlx_push_img();
	return (1);
}

int key_hook(int keycode, void *param)
{
	t_data	*d;

	d = _data();
	if (keycode == 65362)
		render(d->len, d->origin.real, d->origin.img - d->len / 10);
	else if (keycode == 65364)
		render(d->len, d->origin.real, d->origin.img + d->len / 10);
	else if (keycode == 65361)
		render(d->len, d->origin.real - d->len / 10, d->origin.img);
	else if (keycode == 65363)
		render(d->len, d->origin.real + d->len / 10, d->origin.img);
	else if (keycode == 65451)
		render(d->len * 0.75, d->origin.real, d->origin.img);
	else if (keycode == 65453)
		render(d->len * 1.25, d->origin.real, d->origin.img);
	return (dprintf(1, "key: %d     param: %p\n", keycode, param));
}

int mouse_hook(int mousecode, void *param)
{
	t_data	*d;

	d = _data();
	if (mousecode == 4)
		render(d->len * 0.75, d->origin.real, d->origin.img);
	else if (mousecode == 5)
		render(d->len * 1.25, d->origin.real, d->origin.img);
	return (dprintf(1, "mouse: %d     param: %p\n", mousecode, param));
}

int	main(void)
{
	t_data	*data;

	data = _data();
	ft_data_init(720);
	render(4, 0, 0);
	mlx_key_hook (data->win_ptr, key_hook, data->mlx_ptr);
	mlx_mouse_hook(data->win_ptr, mouse_hook, data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
	return (ft_free(), 0);
}
