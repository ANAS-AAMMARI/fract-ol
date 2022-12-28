/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:40:47 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/27 13:31:30 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define MAX_ITER 160

typedef struct fractol_s
{
	char	*julia;
	double	move_x;
	double	move_y;
	double	zr;
	double	zi;
	double	new_cr;
	double	new_ci;
	double	x_win;
	double	y_win;
	double	c_real;
	double	c_img;
	int		color;
	void	*img;
	char	*addr;
	void	*mlx_ptr;
	void	*win_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*fract_type;
	double	madel_pln_p;
	double	madel_pln_n;
	int		color_id;
	int		color_ran;
}	t_fractol;

int		ft_strcmp(const char *s1, const char *s2);
void	ft_putendl(char *s, int fd);
void	def_value_ofjulia(t_fractol *data);
void	fractols(void);
void	range_color(t_fractol *data);
void	case_mandel(t_fractol *fract);
void	ur_fractol_type(t_fractol *fract);
void	mlx_win_init(t_fractol *data);
void	mlx_img_put(t_fractol *data, int x, int y, int color);
void	mandelbrot(t_fractol *fract);
double	map(double out_s, double out_e, double inp_e, double inp);
void	julia(t_fractol *fract);
int		key_hook(int key, t_fractol *data);
int		ft_close(void);
void	burning_ship(t_fractol *fract);
int		mouse_zoom_hook(int mouseCode, int x, int y, t_fractol *data);
#endif