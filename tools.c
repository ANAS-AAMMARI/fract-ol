/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:11:35 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/27 13:33:01 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key, t_fractol *data)
{
	if (key == 53)
		exit(1);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (key == 123)
		data->move_x -= 0.3;
	else if (key == 124)
		data->move_x += 0.3;
	else if (key == 126)
		data->move_y -= 0.3;
	else if (key == 125)
		data->move_y += 0.3;
	if (key == 8)
	{
		data->color_id++;
		if (data->color_id > 7)
			data->color_id = 0;
	}	
	data->x_win = -1;
	ur_fractol_type(data);
	return (0);
}

int	ft_close(void)
{
	exit(1);
	return (0);
}

void	check_bounded_burning_ship(t_fractol *fract, int *n)
{
	*n = 0;
	while (*n < MAX_ITER)
	{
		fract->zr = pow(fract->c_real, 2)
			- pow(fract->c_img, 2);
		fract->zi = 2 * fabs(fract->c_real * fract->c_img);
		fract->c_real = fract->zr + fract->new_cr;
		fract->c_img = fract->zi + fract->new_ci;
		(*n)++;
		if (pow(fract->c_real, 2)
			+ pow(fract->c_img, 2) > 4)
			break ;
	}
}

void	burning_ship(t_fractol *fract)
{
	int	n;

	range_color(fract);
	while (++fract->x_win < WIDTH)
	{
		fract->y_win = -1;
		while (++fract->y_win < WIDTH)
		{
			case_mandel(fract);
			fract->new_cr = fract->c_real;
			fract->new_ci = fract->c_img;
			check_bounded_burning_ship(fract, &n);
			fract->color = 0;
			if (n < MAX_ITER)
				fract->color = fract->color_ran * n;
			mlx_img_put(fract, fract->x_win,
				fract->y_win, fract->color);
		}
	}
	mlx_put_image_to_window(fract->mlx_ptr,
		fract->win_ptr, fract->img, 0, 0);
}

int	mouse_zoom_hook(int mouseCode, int x, int y, t_fractol *data)
{
	(void)y;
	(void)x;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	data->move_x = 0;
	data->move_y = 0;
	if (mouseCode == 5 && data->madel_pln_p >= 0)
	{
		data->madel_pln_p -= 0.3;
		data->madel_pln_n += 0.3;
		data->x_win = -1;
	}
	if (mouseCode == 4)
	{
		data->madel_pln_p += 0.3;
		data->madel_pln_n -= 0.3;
		data->x_win = -1;
	}
	ur_fractol_type(data);
	return (0);
}
