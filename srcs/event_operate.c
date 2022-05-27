/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_operate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:03:16 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/27 01:14:59 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_operate.h"
#include "minirt.h"
#include "time.h"

void	quit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	exit(0);
}

void	reset(t_minirt *rt)
{
	free(rt->cam);
	ft_lstclear(&(rt->objs), free_objs);
	ft_lstclear(&(rt->lights), free);
	read_file_init(rt->file_name, &(rt->cam), &(rt->objs), &(rt->lights));
}

int	red_button_press(t_minirt *rt)
{
	quit(rt->mlx);
	return (0);
}

int	key_press(int key_code, t_minirt *rt)
{
	if (key_code == KEY_ESC)
		quit(rt->mlx);
	else if (key_code == KEY_R)
		reset(rt);
	return (0);
}

int	render(t_minirt *rt)
{
	int	x;
	int	y;
	float	render_start, render_end, trace_end, image_start, image_end;

	render_start = clock();
	ray_trace(rt->image, rt->cam, rt->objs, rt->lights);
	trace_end = clock();
	image_start = clock();
	y = 0;
	while (y < rt->image->height)
	{
		x = 0;
		while (x < rt->image->width)
		{
			rt->mlx->mlx_pixel[(y * rt->mlx->lb) + x] = \
			convert_rgb(rt->image->pixel[y][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(rt->mlx->mlx_ptr, rt->mlx->win, \
	rt->mlx->mlx_image, 0, 0);
	image_end = clock();
	render_end = clock();
	printf("render time : %.3fs | ray_trace time : %.3fs | image_load time : %.3fs\n", \
	(render_end - render_start) / CLOCKS_PER_SEC, (trace_end - render_start) / CLOCKS_PER_SEC, (image_end - image_start) / CLOCKS_PER_SEC);
	return (0);
}
