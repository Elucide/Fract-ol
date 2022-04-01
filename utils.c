/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:28:16 by yschecro          #+#    #+#             */
/*   Updated: 2022/04/01 17:17:56 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

float	squared_modulus(complex c)
{
	return (sqrt((c.real * c.real) + (c.img * c.img)));
}

void	img_pixel_put(int x, int y, int color)
{
	char	*pixel;
	t_data	*data;

	data = _data();
	if (x > 0 && x < data->h && y > 0 && y < data->w)
	{
		pixel = data->img.addr + (y * data->img.len + x * (data->img.bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

int	mlx_push_img(void)
{
	int		i;
	t_data	*d;

	d = _data();
	i = mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.img_ptr, 0, 0);
	return (i);
}

void	mlx_img_addr(void)
{
	t_data	*d;

	d = _data();
	d->img.addr = mlx_get_data_addr(d->img.img_ptr, &d->img.bpp, \
		&d->img.len, &d->img.endian);
}

void	ft_free(void)
{
	t_data	*data;

	data = _data();
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->img.addr);
}
