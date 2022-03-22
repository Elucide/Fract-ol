/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:46:34 by yschecro          #+#    #+#             */
/*   Updated: 2022/03/22 11:48:57 by yschecro         ###   ########.fr       */
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

typedef struct pos
{
	int		x;
	int		y;
} pos;

typedef struct s_img 
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
} t_img;

typedef struct s_data
{
	t_img	img;
	void	*mlx_ptr;
	void	*win_ptr;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	len;
	double	step;
	complex	origin;
	int		x;
	int		y;
	int		h;
	int		w;
} t_data;

#ifndef FRACT_OL_H
# define FRACT_OL_H

int		main(void);
float	squared_modulus(complex c);
void	img_pixel_put(int x, int y, int color);
int	mlx_push_img(void);
void	mlx_img_addr(void);
int		mandelbrot(int rate, complex c);
int		julia(int rate, complex c);
int		rgb(int iter);
void	screen(int (*f)(int, complex));
t_data	*_data(void);
t_data	ft_data_init(int res);


#endif

