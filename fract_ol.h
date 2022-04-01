/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:46:34 by yschecro          #+#    #+#             */
/*   Updated: 2022/04/01 16:37:57 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>

#define _C_I 1	

typedef struct complex
{
	double	real;
	double	img;
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
	t_img		img;
	void		*mlx_ptr;
	void		*win_ptr;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double	len;
	double	step;
	complex		origin;
	int			(*f)(int, complex);
	int			x;
	int			res;
	int			y;
	int			h;
	int			mode;
	int			w;
	int			exit;
} t_data;

#ifndef FRACT_OL_H
# define FRACT_OL_H

int		main(int ac, char **av);
float	squared_modulus(complex c);
void	img_pixel_put(int x, int y, int color);
int		mlx_push_img(void);
void	mlx_img_addr(void);
int		mandelbrot(int rate, complex c);
int		julia(int rate, complex c);
int		burning_ship(int rate, complex c);
int		rgb(int iter,int mode);
int		render(float len, float o_x, float o_y);
int		ft_strcheck(char *s1, char *s2);
int		mouse_hook(int mousecode, void *param);
int		key_hook(int keycode, void *param);
void	screen(int (*f)(int, complex));
t_data	*_data(void);
t_data	ft_data_init(int res);
void	ft_free(void);
char	*ft_strcpy(char *s1, char *s2);


#endif

