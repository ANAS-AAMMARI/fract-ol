/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:18:33 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/27 11:55:21 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double pos, double inp_end, double out_start, double out_end)
{
	return (out_start + (pos * (out_end - out_start)) / inp_end);
}

void	mlx_img_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	check_bounded(t_fractol *fract, int *n)
{
	*n = 0;
	while (*n < MAX_ITER)
	{
		fract->zr = pow(fract->c_real, 2)
			- pow(fract->c_img, 2);
		fract->zi = 2 * fract->c_real * fract->c_img;
		fract->c_real = fract->zr + fract->new_cr;
		fract->c_img = fract->zi + fract->new_ci;
		(*n)++;
		if (pow(fract->c_real, 2)
			+ pow(fract->c_img, 2) > 4)
			break ;
	}
}

void	mandelbrot(t_fractol *fract)
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
			check_bounded(fract, &n);
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

void	julia(t_fractol *fract)
{
	int	n;

	range_color(fract);
	while (++fract->x_win < WIDTH)
	{
		fract->y_win = -1;
		while (++fract->y_win < WIDTH)
		{
			case_mandel(fract);
			check_bounded(fract, &n);
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
