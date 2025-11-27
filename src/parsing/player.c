#include "cub3d.h"

static void	set_dir(t_player *p, double dx, double dy)
{
	p->dir_x = dx;
	p->dir_y = dy;
}

static void	set_plane(t_player *p, double px, double py)
{
	p->plane_x = px;
	p->plane_y = py;
}

static void	set_orientation(t_player *player, char dir)
{
	if (dir == 'N')
	{
		set_dir(player, 0, -1);
		set_plane(player, 0.66, 0);
	}
	else if (dir == 'S')
	{
		set_dir(player, 0, 1);
		set_plane(player, -0.66, 0);
	}
	else if (dir == 'E')
	{
		set_dir(player, 1, 0);
		set_plane(player, 0, 0.66);
	}
	else if (dir == 'W')
	{
		set_dir(player, -1, 0);
		set_plane(player, 0, -0.66);
	}
}

static int	handle_cell(t_game *game, int x, int y, int *has_player)
{
	char	c;

	c = game->map.grid[y][x];
	if (c == '0' || c == '1' || c == ' ')
		return (0);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (*has_player)
			return (print_error("Multiple player positions"));
		*has_player = 1;
		game->player.x = x + 0.5;
		game->player.y = y + 0.5;
		set_orientation(&game->player, c);
		game->map.grid[y][x] = '0';
		return (0);
	}
	return (print_error("Invalid character in map"));
}

int	setup_player(t_game *game)
{
	int	x;
	int	y;
	int	has_player;

	has_player = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (handle_cell(game, x, y, &has_player))
				return (1);
			x++;
		}
		y++;
	}
	if (!has_player)
		return (print_error("Missing player start"));
	return (0);
}
