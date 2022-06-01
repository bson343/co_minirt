#ifndef OBJ_VIEWER_H
# define OBJ_VIEWER_H

# include <stdio.h>
#include "minirt_objs.h"

void	view_vec3(char *name, t_vec3 v);
void	view_matrix_44(char *name, float m[4][4]);
void	draw_big_border(void);
void	draw_small_border(void);
void	view_f(char *name, float f);
void	view_i(char *name, int i);
void	view_camera(t_camera *c);
void	view_sphere(t_sphere *sp);
void	view_plane(t_plane *pl);
void	view_cylinder(t_cylinder *cy);
void	view_light(t_light *l);
void	view_disk(t_disk *d);
void	view_list_light(char *name, t_list *list);
void	view_list_objs(char *name, t_list *list);
void	view_minirt(t_minirt *rt);

#endif
