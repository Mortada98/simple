/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbou-dou <hbou-dou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:17:57 by hbou-dou          #+#    #+#             */
/*   Updated: 2025/12/17 17:17:58 by hbou-dou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi_strict(const char *str, int *out)
{
	long	result;
	int		i;

	if (!str || !str[0])
		return (1);
	result = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			return (1);
		result = result * 10 + (str[i] - '0');
		if (result > 2147483647)
			return (1);
		i++;
	}
	*out = (int)result;
	return (0);
}
