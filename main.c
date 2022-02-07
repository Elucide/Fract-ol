/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:52:33 by yschecro          #+#    #+#             */
/*   Updated: 2022/02/07 17:56:57 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	mandelbrot(int rate, void *mlx, void *mlx_win, int height, int width)
{
	int	x;
	int	y;
	int n;
	double _Complex c = 0 + _Complex_I;
	double _Complex z = 0;

	x = 0;
	y = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			while (rate < n)
			y++;
		}
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		x = 200;
	int		y = 200;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 2000, "fract-ol");
	mandelbrot(10, mlx, mlx_win, 1000, 2000);
	mlx_loop(mlx);
	return (0);
}
