/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouizak <mbouizak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:25:20 by mbouizak          #+#    #+#             */
/*   Updated: 2025/12/17 17:25:52 by mbouizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_error(const char *msg)
{
	int	len;

	write(2, "Error\n", 6);
	if (!msg)
		return (1);
	len = ft_strlen(msg);
	if (len > 0)
		write(2, msg, len);
	write(2, "\n", 1);
	return (1);
}
