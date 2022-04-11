/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:52:33 by yschecro          #+#    #+#             */
/*   Updated: 2022/04/11 14:42:56 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_data	*_data(void)
{
	static t_data	data;

	return (&data);
}

t_data	ft_data_init(int res)
{
	t_data	*data;

	data = _data();
	data->res = res;
	data->exit = 0;
	data->rate = 80;
	data->h = res;
	data->mode = 0;
	data->maths = 0;
	data->w = res;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w, data->h, "fract-ol");
	return (*data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (write(1, "not enough arg\0", 16));
	data = _data();
	ft_data_init(720);
	if (ft_strcheck(av[1], "mandelbrot"))
		data->f = &mandelbrot;
	else if (ft_strcheck(av[1], "julia"))
		data->f = &julia;
	else if (ft_strcheck(av[1], "burning_ship"))
		data->f = &burning_ship;
	else
		return (write(1, \
			"\n\nwrong arg\nTry with mandelbrot, julia or burning_ship\n", 55));
	render(4, 0, 0);
	mlx_key_hook (data->win_ptr, key_hook, data->mlx_ptr);
	mlx_mouse_hook(data->win_ptr, mouse_hook, data->mlx_ptr);
	if (data->exit)
		return (ft_free(), 0);
	mlx_loop(data->mlx_ptr);
	return (ft_free(), 0);
}
