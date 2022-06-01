#include "minirt_objs.h"
#include "obj_viewer.h"

void	draw_big_border(void)
{
	printf("==============================\n");
}

void	draw_small_border(void)
{
	printf("-------------------------\n");
}

// # define SP 1
// # define PL 2
// # define CY 3
// # define DI 4

void	view_list_objs(char *name, t_list *list)
{
	t_list	*iter;
	t_objs	*content;

	iter = list;
	printf("%s list\n", name);
	while (iter)
	{
		content = iter->content;
		if (content->id == 1)
			view_sphere((t_sphere *)content->shape);
		else if (content->id == 2)
			view_plane((t_plane *)content->shape);
		else if (content->id == 3)
			view_cylinder((t_cylinder *)content->shape);
		else if (content->id == 4)
			view_disk((t_disk *)content->shape);
		view_vec3("rgb", content->rgb);
		draw_small_border();
		iter = iter->next;
	}

}

void	view_list_light(char *name, t_list *list)
{
	t_list	*iter;
	t_light	*content;

	iter = list;
	printf("%s list\n", name);
	while (iter)
	{
		content = iter->content;
		view_light(content);
		view_vec3("rgb", content->rgb);
		draw_small_border();
		iter = iter->next;
	}
}

void	view_disk(t_disk *d)
{
	printf("Disk :\n");
	view_vec3("origin", d->origin);
	view_vec3("n", d->n);
}
