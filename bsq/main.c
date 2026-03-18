#include "bsq.h"

static void	init_map(t_map *map)
{
	map->rows = 0;
	map->cols = 0;
	map->empty = 0;
	map->obstacle = 0;
	map->full = 0;
	map->grid = NULL;
}

static int	run_map(char *content)
{
	t_map		map;
	t_square   	max;
	int			map_start;

	init_map(&map);
	if (!parse_header(content, &map, &map_start))
		return (0);
	if (!validate_map(content, &map, map_start))
		return (0);
	if (!build_grid(content, &map, map_start))
		return (0);
	max = solve_bsq(&map);
	draw_square(&map, &max);
	print_map(&map);
	free_map(&map);
	return (1);
}

static int	process_fd(int fd)
{
	char	*content;
	int		ok;

	content = read_file(fd);
	if (!content)
		return (0);
	ok = run_map(content);
	free(content);
	return (ok);
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	if (argc == 1)
    {
        if (!process_fd(0))
            print_error();
        return (0);
    }
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0 || !process_fd(fd))
			print_error();
		if (fd >= 0)
			close(fd);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}