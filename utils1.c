/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:16:10 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/27 13:32:08 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	case_mandel(t_fractol *fract)
{
	fract->c_real = map(fract->x_win, WIDTH,
			(fract->madel_pln_n - fract->move_x),
			(fract->madel_pln_p - fract->move_x));
	fract->c_img = map(fract->y_win, WIDTH,
			(fract->madel_pln_n - fract->move_y),
			(fract->madel_pln_p - fract->move_y));
}

void	ur_fractol_type(t_fractol *fract)
{
	if (ft_strcmp(fract->fract_type, "Mandelbrot") == 0
		|| ft_strcmp(fract->fract_type, "1") == 0)
		mandelbrot(fract);
	else if (ft_strcmp(fract->fract_type, "Julia") == 0
		|| ft_strcmp(fract->fract_type, "2") == 0)
	{
		def_value_ofjulia(fract);
		julia(fract);
	}
	else if (ft_strcmp(fract->fract_type, "BurningShip") == 0
		|| ft_strcmp(fract->fract_type, "3") == 0)
		burning_ship(fract);
	else
	{
		fractols();
		exit(1);
	}	
}

void	range_color(t_fractol *data)
{
	if (data->color_id == 0)
		data->color_ran = 0xff0801;
	else if (data->color_id == 1)
		data->color_ran = 0xfff600;
	else if (data->color_id == 2)
		data->color_ran = 0x18ff00;
	else if (data->color_id == 3)
		data->color_ran = 0xf4f4f5;
	else if (data->color_id == 4)
		data->color_ran = 0xb0ffd9;
	else if (data->color_id == 5)
		data->color_ran = 0xffffd9;
	else if (data->color_id == 6)
	data->color_ran = 0xFFFCA7;
	else if (data->color_id == 7)
	data->color_ran = 0xf1f1e1;
}

void	fractols(void)
{
	ft_putendl(" 1- Mandelbrot   \n", 1);
	ft_putendl(" 2- Julia        \n", 1);
	ft_putendl(" 3- BurningShip    ", 1);
}
