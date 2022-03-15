/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:28:16 by yschecro          #+#    #+#             */
/*   Updated: 2022/03/15 17:04:05 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"


float	squared_modulus(complex c)
{
	return (sqrt((c.real * c.real) + (c.img * c.img)));
}


void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	mlx_push_img(t_data d)
{
	int	i;

	i = mlx_put_image_to_window(d.mlx_ptr, d.win_ptr, d.img.img_ptr, 0, 0);
	return (i);
}

void	mlx_img_addr(t_data d)
{
	char	*c;
	c = mlx_get_data_addr(&d.img.img_ptr, &d.img.bpp, &d.img.len, &d.img.endian);
	d.img.addr = c;
}

