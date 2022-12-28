/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:48:02 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/27 12:41:15 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putendl(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	julia_set_rest(t_fractol *data, char *cmd)
{
	if (ft_strcmp(cmd, "6") == 0)
	{
		data->new_cr = -0.7269;
		data->new_ci = 0.1889;
	}
	else if (ft_strcmp(cmd, "5") == 0)
	{
		data->new_cr = -0.8;
		data->new_ci = 0.156;
	}
	else
	{
		ft_putendl(" 1- julia cr= -0.4  ci= 0.6         \n", 1);
		ft_putendl(" 2- julia cr= 0.285 ci= 0.01        \n", 1);
		ft_putendl(" 3- julia cr= -0.70176 ci= 0.3842   \n", 1);
		ft_putendl(" 4- julia cr= 0 ci= -08             \n", 1);
		ft_putendl(" 5- julia cr= -0.8 ci= 0.156        \n", 1);
		ft_putendl(" 6- julia cr= -0.7269 ci= 0.1889    \n", 1);
		exit(1);
	}
}

void	julia_set_range(t_fractol *data, char *cmd)
{
	if (ft_strcmp(cmd, "1") == 0)
	{
		data->new_cr = -0.4;
		data->new_ci = 0.6;
	}
	else if (ft_strcmp(cmd, "2") == 0)
	{
		data->new_cr = 0.285;
		data->new_ci = 0.01;
	}
	else if (ft_strcmp(cmd, "3") == 0)
	{
		data->new_cr = -0.70176;
		data->new_ci = 0.3842;
	}
	else if (ft_strcmp(cmd, "4") == 0)
	{
		data->new_cr = 0;
		data->new_ci = -0.8;
	}
	else
		julia_set_rest(data, cmd);
}

void	def_value_ofjulia(t_fractol *data)
{
	if (!data->julia)
	{
		ft_putendl(" 1- julia cr= -0.4  ci= 0.6         \n", 1);
		ft_putendl(" 2- julia cr= 0.285 ci= 0.01        \n", 1);
		ft_putendl(" 3- julia cr= -0.70176 ci= 0.3842   \n", 1);
		ft_putendl(" 4- julia cr= 0 ci= -08             \n", 1);
		ft_putendl(" 5- julia cr= -0.8 ci= 0.156        \n", 1);
		ft_putendl(" 6- julia cr= -0.7269 ci= 0.1889    \n", 1);
		exit(1);
	}
	else
		julia_set_range(data, data->julia);
}
