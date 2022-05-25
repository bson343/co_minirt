#include "minirt.h"

static void	parsing_line(char *line, t_minirt *minirt)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i + 1] && line[i + 1] == ' ' && line[i] == 'A')
		parsing_ambient(minirt, line, i + 1);
	else if (line[i + 1] && line[i + 1] == ' ' && line[i] == 'C')
		parsing_camera(minirt, line, i + 1);
	else if (line[i + 1] && line[i + 1] == ' ' && line[i] == 'L')
		parsing_light(minirt, line, i + 1);
	else if (line[i + 2] && line[i + 2] == ' ' && \
		(line[i] == 's' && line[i + 1] == 'p'))
		parsing_sphere(minirt, line, i + 2);
	else if (line[i + 2] && line[i + 2] == ' ' && \
		(line[i] == 'p' && line[i + 1] == 'l'))
		parsing_plane(minirt, line, i + 2);
	else if (line[i + 2] && line[i + 2] == ' ' && \
		(line[i] == 'c' && line[i + 1] == 'y'))
		parsing_cylinder(minirt, line, i + 2);
	else
		ft_error(ERROR_BAD_FORMAT);
}


void	parser(char *filename, t_minirt *minirt)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error(ERROR_FILE_OPEN);
	while (get_next_line(fd, &line))
	{
		if (is_empty(line))
		{
			free(line);
			continue;
		}
		parsing_line(line, minirt);
		free(line);
	}
}
