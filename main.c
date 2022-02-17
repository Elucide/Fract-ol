/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:52:33 by yschecro          #+#    #+#             */
/*   Updated: 2022/02/17 19:14:29 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

float	squared_modulus(complex c)
{
	return (sqrt((c.real * c.real) + (c.img * c.img)));
}
/*
void	mandelbrot(int rate, void *mlx, void *mlx_win, int height, int width)
{
	int		n = 0;
	complex	c;
	complex	z;
	complex	temp;

	c.real = -(width / 2);
	c.img =  -(height / 2);
	while (c.real < (width / 2))
	{
		c.img = -((float)height / 2) ;
		while (c.img < (height / 2) )
		{
			z.real = 0;
			z.img = 0;
			n = 0;
			while (rate > n)
			{
				mlx_pixel_put(mlx, mlx_win, (int)c.real + width / 2, (int)c.img + height / 2, 10040319);
				temp.real = (c.real * c.real) - (c.img * c.img) + z.real;
				z.img = 2 * c.real * c.img + z.img;
				z.real = temp.real;
				if (squared_modulus(z) > 4)
				{
					//					printf("squared modulus of z:%f\n", squared_modulus(z));
					mlx_pixel_put(mlx, mlx_win, (int)c.real + width / 2, (int)c.img + height / 2, 1489139);
					break ;
				}
				n++;
				//				printf("Im(z) = %f	:	Re(z) = %f\n", z.img, z.real);
			}
			c.img++;
		}
		c.real++;
	}
}
*/
void	mandelbrot(int rate, size s, mlx m, complex c)
{
	complex	z;
	complex	temp;
	int		n;
	int		done;

	done = 0;
	z.real = 0;
	z.img = 0;
	n = 0;
	while (n < rate && done == 0)
	{
//		mlx_pixel_put(m.mlx, m.win, c.real + s.w / 2, c.img + s.h / 2, 10040319);
		temp.real = (c.real * c.real) - (c.img * c.img) + z.real;
		z.img = 2 * c.real * c.img + z.img;
		z.real = temp.real;
		if (squared_modulus(z) > 4)
		{
			mlx_pixel_put(m.mlx, m.win, c.real + s.w / 2, c.img + s.h / 2, 1489139);
			done = 1;
		}
		n++;
	}
	c.img++;
}

void	screen(mlx m, size s, void(*f)(int, size, mlx, complex))
{
	complex	c;

	c.real = -(s.w / 2);
	c.img =  -(s.h / 2);
	while (c.real < (s.w / 2))
	{
		c.img = -(s.h / 2) ;
		while (c.img < (s.h / 2) )
		{
			f(10, s, m, c);
			c.img++;
		}
		c.real++;
	}
}	

void	pouce(size scale, size s, )


int	main(void)
{
	mlx		m;
	size	s;

	s.h = 720;
	s.w = 1080;
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, s.w, s.h, "fract-ol");
//	mandelbrot(10, mlx, mlx_win, height, width);
	screen(m, s, &mandelbrot);
	mlx_loop(m.mlx);
	printf("mandelbrot printed\n");
	return (free(m.mlx), free(m.win), 0);
}
