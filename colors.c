/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:24:44 by yschecro          #+#    #+#             */
/*   Updated: 2022/03/28 19:56:38 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	rgb(int iter)
{
	double	r;
	double	g;
	double	b;
	int		color;

	r = sin(0.3 * (double)iter);
	g = sin(0.3 * (double)iter) + rand() * 500;
	b = sin(0.3 * (double)iter) * 127;
	color = ((int)(255.999 * r) << 16) + ((int)(255.999 * g) << 8) \
			+ ((int)(255.999 * b));
	return (color);
}
