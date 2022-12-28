/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:49:57 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/27 13:32:33 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_win_init(t_fractol *data)
{
	data->move_x = 0;
	data->move_y = 0;
	data->color_id = 0;
	data->madel_pln_p = 2;
	data->madel_pln_n = -2;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, WIDTH, "Fractol");
	data->img = mlx_new_image(data->mlx_ptr, WIDTH, WIDTH);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

int	main(int ac, char *av[])
{
	t_fractol	fract;

	(void)av;
	if (ac == 3 || ac == 2)
	{
		fract.x_win = -1;
		fract.fract_type = av[1];
		fract.julia = av[2];
		mlx_win_init(&fract);
		ur_fractol_type(&fract);
		mlx_mouse_hook(fract.win_ptr, mouse_zoom_hook, &fract);
		mlx_key_hook(fract.win_ptr, key_hook, &fract);
		mlx_hook(fract.win_ptr, 17, 0L, ft_close, NULL);
		mlx_loop((&fract)->mlx_ptr);
	}
	else if (ac < 2)
		fractols();
}
