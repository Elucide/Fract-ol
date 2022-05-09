/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:25:21 by yschecro          #+#    #+#             */
/*   Updated: 2022/05/09 18:51:12 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static long	mouse(int n)
{
	t_data	*d;

	d = _data();
	return (d->len * ((n - (n / 2)) / d->res));
}

int	mouse_hook(int mousecode, int x, int y, void *param)
{
	t_data	*d;

	d = _data();
	if (!param)
		return (0);
	dprintf(1, "x : %ld     y : %ld\n", mouse(x), mouse(y));
	if (mousecode == 4)
		render(d->len * 0.75,/* d->origin.real +*/ \
			mouse(x),/* d->origin.img +*/ mouse(y));
	else if (mousecode == 5)
		render(d->len * 1.25, d->origin.real, d->origin.img);
	return (0);
}

static int	color_mode(int mode)
{
	if (mode >= 0 && mode <= 2)
		return (mode++);
	else if (mode == 3)
		return (0);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_data	*d;

	d = _data();
	if (keycode == 65362)
		render(d->len, d->origin.real, d->origin.img - d->len / 10);
	else if (keycode == 65364)
		render(d->len, d->origin.real, d->origin.img + d->len / 10);
	else if (keycode == 65361)
		render(d->len, d->origin.real - d->len / 15, d->origin.img);
	else if (keycode == 65363)
		render(d->len, d->origin.real + d->len / 15, d->origin.img);
	else if (keycode == 65506)
	{
		d->mode = color_mode(d->mode);
		render(d->len, d->origin.real, d->origin.img);
	}
	else if (keycode == 65293)
	{
		d->maths++;
		render(d->len, d->origin.real, d->origin.img);
	}
	else if (keycode == 65307)
		ft_free();
	return (dprintf(1, "key = %d   param == %p\n", keycode, param));
}
