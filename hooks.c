/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:25:21 by yschecro          #+#    #+#             */
/*   Updated: 2022/03/28 20:11:13 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_hook(int mousecode, void *param)
{
	t_data	*d;

	d = _data();
	if (!param)
		return (0);
	if (mousecode == 4)
		render(d->len * 0.75, d->origin.real, d->origin.img);
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
	else if (keycode == 65451)
		render(d->len * 0.75, d->origin.real, d->origin.img);
	else if (keycode == 65453)
		render(d->len * 1.25, d->origin.real, d->origin.img);
	else if (keycode == 65307)
		d->exit = 1;
	return (dprintf(1, "key: %d     param: %p\n", keycode, param));
}
