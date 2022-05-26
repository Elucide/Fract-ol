/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:25:21 by yschecro          #+#    #+#             */
/*   Updated: 2022/05/26 15:54:46 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol_bonus.h"

static double	mouse(float n)
{
	t_data	*d;

	d = _data();
	return (n * d->step - (d->len / 2));
}

int	julia_move(int x, int y, void *param)
{
	t_data	*d;

	d = _data();
	if (!param || !d->can_read)
		return (0);
	d->j.real = mouse((float)x);
	d->j.img = mouse((float)y);
	d->can_read = 0;
	render(d->len, d->origin.real, d->origin.img);
	return (1);
}

int	mouse_hook(int mousecode, int x, int y, void *param)
{
	t_data	*d;

	d = _data();
	if (!param)
		return (0);
	if (mousecode == 4)
		render(d->len * 0.75, \
			d->origin.real + mouse(x) / 1.5, d->origin.img + mouse(y) / 1.5);
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
	else if (d->mode == 1)
		d->mode = 2;
	else if (d->mode == 2)
		d->mode = 0;
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
	else if (keycode == 65307)
		close_win(0);
	else if (keycode == 65506)
	{
		color_mode();
		render(d->len, d->origin.real, d->origin.img);
	}
	else if (keycode == 65293)
	{
		d->maths++;
		render(d->len, d->origin.real, d->origin.img);
	}
	return ((void) param, 1);
}
