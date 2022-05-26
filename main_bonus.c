/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:52:33 by yschecro          #+#    #+#             */
/*   Updated: 2022/05/24 17:01:12 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol_bonus.h"

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
	data->rate = 90;
	data->can_read = 1;
	data->h = res;
	data->mode = 0;
	data->maths = 0;
	data->w = res;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr)
		data->win_ptr = \
			mlx_new_window(data->mlx_ptr, data->w, data->h, "fract-ol");
	return (*data);
}

int	close_win(int param)
{
	t_data	*data;

	data = _data();
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	exit(param);
	return (EXIT_SUCCESS);
}

static void	*fractal(int ac, char **av)
{
	t_data	*data;

	data = _data();
	if (ac == 2)
	{
		if (ft_strcheck(av[1], "mandelbrot"))
			return (&mandelbrot);
		else if (ft_strcheck(av[1], "julia"))
			return (&julia);
		else if (ft_strcheck(av[1], "burning_ship"))
			return (&burning_ship);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = _data();
	data->f = fractal(ac, av);
	if (!data->f)
		return (write(1, ERROR, 55));
	ft_data_init(720);
	if (data->win_ptr && data->mlx_ptr)
	{
		render(4, 0, 0);
		mlx_key_hook (data->win_ptr, key_hook, data->mlx_ptr);
		mlx_mouse_hook(data->win_ptr, mouse_hook, data->mlx_ptr);
		mlx_hook(data->win_ptr, 17, 0, close_win, 0);
		mlx_hook(data->win_ptr, 6, 1L << 8, julia_move, data->mlx_ptr);
		mlx_loop(data->mlx_ptr);
	}
	else
		close_win(0);
	return (0);
}
