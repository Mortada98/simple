/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouizak <mbouizak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:25:06 by mbouizak          #+#    #+#             */
/*   Updated: 2025/12/17 17:25:52 by mbouizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_background(t_game *game)
{
	int	x;
	int	y;
	int	ceiling;
	int	floor;

	ceiling = rgb_to_int(game->config.ceiling);
	floor = rgb_to_int(game->config.floor);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				draw_pixel(&game->frame, x, y, ceiling);
			else
				draw_pixel(&game->frame, x, y, floor);
			x++;
		}
		y++;
	}
}
