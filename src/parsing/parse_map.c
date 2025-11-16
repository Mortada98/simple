#include "cub3d.h"

int	add_map_line(t_map *map, char *line)
{
	char	**new_grid;
	char	*clean_line;
	int		len;
	int		i;

	len = ft_strlen(line);
	while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
		len--;
	clean_line = ft_strndup(line, len);
	if (!clean_line)
		return (print_error("Memory allocation failed"));
	new_grid = safe_malloc(sizeof(char *) * (map->height + 2));
	i = 0;
	while (i < map->height)
	{
		new_grid[i] = map->grid[i];
		i++;
	}
	new_grid[map->height] = clean_line;
	new_grid[map->height + 1] = NULL;
	if (map->grid)
		free(map->grid);
	map->grid = new_grid;
	map->height++;
	return (0);
}

static int	row_width(const char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
		i++;
	return (i);
}

static void	fill_row(char *dst, const char *src, int width)
{
	int	i;
	int	src_len;

	src_len = 0;
	if (src)
		src_len = ft_strlen(src);
	i = 0;
	while (i < width)
	{
		if (src && i < src_len)
			dst[i] = src[i];
		else
			dst[i] = ' ';
		i++;
	}
	dst[width] = '\0';
}

static int	get_max_width(char **lines, int count)
{
	int	i;
	int	width;
	int	tmp;

	width = 0;
	i = 0;
	while (i < count)
	{
		tmp = row_width(lines[i]);
		if (tmp > width)
			width = tmp;
		i++;
	}
	return (width);
}

int	finalize_map_grid(t_map *map)
{
	int		width;
	int		i;
	char	*tmp;

	if (map->height <= 0)
		return (print_error("Map section is empty"));
	width = get_max_width(map->grid, map->height);
	if (width == 0)
		return (print_error("Map width is zero"));
	map->width = width;
	i = 0;
	while (i < map->height)
	{
		tmp = safe_malloc(width + 1);
		fill_row(tmp, map->grid[i], width);
		free(map->grid[i]);
		map->grid[i] = tmp;
		i++;
	}
	return (0);
}

static void	build_grid_rows(t_map *map, char **lines, int width, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		map->grid[i] = safe_malloc(width + 1);
		fill_row(map->grid[i], lines[i], width);
		free(lines[i]);
		i++;
	}
}

int	finalize_map(t_map *map, char **lines, int count)
{
	int	width;

	if (count <= 0)
		return (print_error("Map section is empty"));
	width = get_max_width(lines, count);
	if (width == 0)
		return (print_error("Map width is zero"));
	map->grid = safe_malloc(sizeof(char *) * count);
	map->width = width;
	map->height = count;
	build_grid_rows(map, lines, width, count);
	return (0);
}
