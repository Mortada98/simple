#include "cub3d.h"

static int	process_line(t_game *game, char *line)
{
	if (game->map.height > 0 || is_map_line(line))
	{
		if (!scene_config_ready(&game->config))
			return (print_error("Map before textures/colors"));
		if (is_all_space(line))
			return (print_error("Empty line inside map"));
		return (add_map_line(&game->map, line));
	}
	return (scene_process_entry(game, line));
}

int	parse_scene(t_game *game, const char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (print_error("Unable to open .cub file"));
	while ((line = get_next_line(fd)) != NULL)
	{
		if (process_line(game, line))
		{
			free(line);
			close(fd);
			return (print_error("Failed to parse file"));
		}
		free(line);
	}
	close(fd);
	if (game->map.height == 0)
		return (print_error("Missing map section"));
	if (finalize_map_grid(&game->map))
		return (1);
	return (validate_scene(game));
}
