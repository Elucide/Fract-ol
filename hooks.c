/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:25:21 by yschecro          #+#    #+#             */
/*   Updated: 2022/05/26 16:02:44 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

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

int	mouse_hook(int mousecode, void *param)
{
	t_data	*d;

	d = _data();
	if (!param || !d->can_read)
		return (0);
	if (mousecode == 4)
		render(d->len * 0.75, \
			d->origin.real, d->origin.img);
	else if (mousecode == 5)
		render(d->len * 1.25, d->origin.real, d->origin.img);
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
	else if (keycode == 65307)
		close_win(0);
	return ((void) param, 1);
}
