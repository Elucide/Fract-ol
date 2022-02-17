/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:46:34 by yschecro          #+#    #+#             */
/*   Updated: 2022/02/17 17:49:39 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define _C_I 1	

typedef struct complex
{
	float	real;
	float	img;
} complex;

typedef struct size 
{
	float	h;
	float	w;
} size;

typedef struct mlx
{
	void *mlx;
	void *win;
} mlx;

#ifndef FRACT_OL_H
# define FRACT_OL_H

int		main(void);

#endif

