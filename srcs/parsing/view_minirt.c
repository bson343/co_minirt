#include "minirt_objs.h"
#include "obj_viewer.h"

void	view_minirt(t_minirt *rt)
{
	draw_big_border();
	view_camera(rt->cam);
	draw_big_border();
	view_list_objs("objs", rt->objs);
	draw_big_border();
	view_list_light("lights", rt->lights);
	draw_big_border();
}
