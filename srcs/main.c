/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:35:37 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/25 21:29:56 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "minirt_error.h"

t_minirt	*new_minirt(char *filename)
{
	t_minirt	*ret;

	ret = (t_minirt *)ft_calloc_assert(1, sizeof(t_minirt));
	ft_memset(ret, 0, sizeof(t_minirt));
	image_init(&(ret->image));
	rt_init(ret, filename);
	return (ret);
}

int	main(int argc, char **argv)
{
	t_minirt	*rt;

	if (argc < 2)
		ft_error(ERROR_NO_ARG);
	if (!ft_strnstr(argv[1], ".rt", ft_strlen(argv[1])))
		ft_error(ERROR_NO_RT_FILE);
	rt = new_minirt(argv[1]);
	//read_file_init(argv[1], &(rt->cam), &(rt->objs), &(rt->lights));
	parser(argv[1], rt);
	mlx_hook(rt->mlx->win, X_EVENT_KEY_PRESS, 0, key_press, rt);
	mlx_hook(rt->mlx->win, X_EVENT_RED_BUTTON_PRESS, 0, red_button_press, rt);
 	mlx_loop_hook(rt->mlx->mlx_ptr, render, rt);
	mlx_loop(rt->mlx->mlx_ptr);
	all_free(rt->image, rt->cam, rt->objs, rt->lights);
	return (0);
}

// static void	objects_data_viewer(t_minirt *minirt)
// {

// }

// void	view_camera(t_camera *camera)
// {
// 	int	i;
// 	int	j;

// 	printf("@@Camera Data@@\n");
// 	view_vector(camera->point, "point");
// 	view_vector(camera->ori, "ori");
// 	printf("fov : %d\n", camera->fov);
// 	printf("world matrix[4][4] : ");
// 	i = -1;
// 	while (++i < 4)
// 	{
// 		j = -1;
// 		printf("[ ");
// 		while (++j < 4)
// 		{
// 			printf("%f", camera->cam_to_world_matrix[i][j]);
// 		}
// 		printf(" ]\n");
// 	}
// }

// void	view_shpae(void *shpae, int id)
// {

// }

// void	print_node(void *node)
// {
// 	t_objs *object;

// 	object = (t_objs *)node;
// 	printf("id : %d\n", object->id);
// }

// void	view_objs(t_list *list)
// {

// }

// void	view_vector(t_vec3 vec, char *name)
// {
// 	printf("%s : (%f, %f, %f)\n", name, vec.e[0], vec.e[1], vec.e[2]);
// }
