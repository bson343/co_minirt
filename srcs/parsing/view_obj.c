/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:05:06 by bson              #+#    #+#             */
/*   Updated: 2022/06/02 13:05:07 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_viewer.h"

void	view_camera(t_camera *c)
{
	printf("Camera :\n");
	view_vec3("point", c->point);
	view_vec3("ori", c->ori);
	view_i("fov", c->fov);
	view_matrix_44("cam_to_world_matrix", c->cam_to_world_matrix);
}

void	view_sphere(t_sphere *sp)
{
	printf("Sphere :\n");
	view_vec3("origin", sp->origin);
	view_f("r", sp->r);
}

void	view_plane(t_plane *pl)
{
	printf("Plane :\n");
	view_vec3("origin", pl->origin);
	view_vec3("n", pl->n);
}

void	view_cylinder(t_cylinder *cy)
{
	printf("Cylinder :\n");
	view_vec3("origin", cy->origin);
	view_vec3("n", cy->n);
	view_f("r", cy->r);
	view_f("h", cy->h);
}

void	view_light(t_light *l)
{
	if (l->id == 1)
		printf("Ambient :\n");
	else
		printf("Light :\n");
	view_vec3("origin", l->origin);
	view_vec3("rgb", l->rgb);
	view_f("bright", l->bright);
}
