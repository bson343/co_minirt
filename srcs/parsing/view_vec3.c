#include "obj_viewer.h"
#include "minirt_objs.h"

void	view_vec3(char *name, t_vec3 v)
{
	printf("%s : \n", name);
	printf("	{%.3f | %.3f | %.3f}\n", v.e[0], v.e[1], v.e[2]);
}

void	view_i(char *name, int i)
{
	printf("%s : %d\n", name, i);
}

void	view_f(char *name, float f)
{
	printf("%s : %.3f\n", name, f);
}

void	view_matrix_44(char *name, float m[4][4])
{
	int	i;
	int	j;

	printf("%s : \n", name);
	printf("	[");
	i = 0;
	while (i < 4)
	{
		printf("{");
		j = 0;
		while (j < 4)
		{
			printf("%.3f", m[i][j]);
			if (j != 3)
				printf(", ");
			++j;
		}
		printf("} ");
		++i;
	}
	printf("]\n");
}
