/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:25:21 by yschecro          #+#    #+#             */
/*   Updated: 2022/05/20 20:53:48 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static double	mouse(float n)
{
	t_data	*d;

	d = _data();
	return ((n - (n * 2)) / 350);
}

int julia_move(int x, int y, void *param)
{
	t_data	*d;

	d = _data();
	if (!param || !d->can_read)
		return (0);
	d->j.real = mouse((float)x);
	d->j.img = mouse((float)y);
	render(d->len, d->origin.real, d->origin.img);
	return (1);
}

int	mouse_hook(int mousecode, int x, int y, void *param)
{
	t_data	*d;

	d = _data();
	if (!param || !d->can_read)
		return (0);
	dprintf(1, "x : %f     y : %f\n", mouse(x), mouse(y));
	if (mousecode == 4)
		render(d->len * 0.75, d->origin.real, d->origin.img);
	else if (mousecode == 5)
		render(d->len * 1.25, d->origin.real, d->origin.img);
	return (0);
}

static void	color_mode(void)
{
	t_data	*d;

	d = _data();
	if (d->mode == 0)
		d->mode = 1;
	if (d->mode == 1)
		d->mode = 2;
	if (d->mode == 2)
		d->mode = 3;
	if (d->mode == 3)
		d->mode = 0;
}

int	key_hook(int keycode, void *param)
{
	t_data	*d;

	d = _data();
	if (!d->can_read)
		return (0);
	if (keycode == 65362)
		render(d->len, d->origin.real, d->origin.img - d->len / 10);
	else if (keycode == 65364)
		render(d->len, d->origin.real, d->origin.img + d->len / 10);
	else if (keycode == 65361)
		render(d->len, d->origin.real - d->len / 15, d->origin.img);
	else if (keycode == 65363)
		render(d->len, d->origin.real + d->len / 15, d->origin.img);
	else if (keycode == 65307)
		close_win(0);	
	else if (keycode == 65506)
	{
		render(d->len, d->origin.real, d->origin.img);
		color_mode();
	}
	else if (keycode == 65293)
	{
		dprintf(1, "d->maths = %d\n", d->maths);
		render(d->len, d->origin.real, d->origin.img);
		d->maths++;
	}
	return (dprintf(1, "key = %d   param == %p\n", keycode, param));
}
