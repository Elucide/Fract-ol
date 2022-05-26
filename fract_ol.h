/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:46:34 by yschecro          #+#    #+#             */
/*   Updated: 2022/05/26 16:03:02 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>

# define ERROR "\n\nwrong arg\nTry with mandelbrot, julia or burning_ship\n"

typedef struct s_complex
{
	double	real;
	double	img;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

typedef struct s_data
{
	t_img		img;
	void		*mlx_ptr;
	void		*win_ptr;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		len;
	double		step;
	t_complex	origin;
	t_complex	j;
	int			(*f)(int, t_complex);
	int			can_read;
	int			x;
	int			res;
	int			y;
	int			h;
	int			rate;
	int			mode;
	int			maths;
	int			w;
	int			exit;
}	t_data;

int			main(int ac, char **av);
float		squared_modulus(t_complex c);
void		img_pixel_put(int x, int y, int color);
int			mlx_push_img(void);
void		mlx_img_addr(void);
int			mandelbrot(int rate, t_complex c);
int			julia(int rate, t_complex c);
int			render(double len, double o_x, double o_y);
int			ft_strcheck(char *s1, char *s2);
int			mouse_hook(int mousecode, void *param);
int			close_win(int param);
int			key_hook(int keycode, void *param);
void		screen(int (*f)(int, t_complex));
t_data		*_data(void);
t_data		ft_data_init(int res);
void		ft_free(void);
char		*ft_strcpy(char *s1, char *s2);
int			julia_move(int x, int y, void *param);

#endif
