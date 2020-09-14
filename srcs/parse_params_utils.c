/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:03:25 by memilio           #+#    #+#             */
/*   Updated: 2020/09/12 15:50:29 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			parse_num_from_line(char *str, int *i)
{
	int		num;

	num = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (num < 10000)
		{
			num *= 10;
			num += str[*i] - 48;
		}
		*i += 1;
	}
	if (str[*i] == ' ' || str[*i] == '\0')
		return (num > 0 ? num : -1);
	return (-1);
}

int			check_is_map(char *line)
{
	int		i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '1'
		|| line[i] == '2' || line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
		|| line[i] == 'W' || line[i] == '0'))
		i++;
	if (line[i] == '\0' && i > 0)
		return (1);
	return (0);
}

int			parse_color_from_line(char *str, int *i)
{
	int		num;
	int		count;

	num = 0;
	count = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num *= 10;
		num += str[*i] - 48;
		*i += 1;
		count++;
	}
	if (count && (str[*i] == ',' || str[*i] == '\0') && num >= 0 && num <= 255)
		return (num);
	return (-1);
}
