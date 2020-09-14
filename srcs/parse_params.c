/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:02:52 by memilio           #+#    #+#             */
/*   Updated: 2020/09/12 13:46:14 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_params_color(char *tmp, unsigned long *color, int *f)
{
	int		i;
	int		num[3];
	int		j;

	i = 1;
	j = 0;
	ft_skip_spaces(tmp, &i);
	while (tmp[i] != '\0' && j < 3)
	{
		if ((num[j] = parse_color_from_line(tmp, &i)) >= 0)
			j++;
		else
			break ;
		if (tmp[i] == ',')
			i++;
	}
	*color = num[0] << 16 | num[1] << 8 | num[2];
	if (j == 3 && tmp[i] == '\0')
	{
		*f = 1;
		return (1);
	}
	return (0);
}

static int	parse_params_r(char *str, t_params *params)
{
	int		i;

	i = 1;
	if (!params->r)
	{
		ft_skip_spaces(str, &i);
		if ((params->r_xy[0] = parse_num_from_line(str, &i)) < 0)
			return (0);
		ft_skip_spaces(str, &i);
		if ((params->r_xy[1] = parse_num_from_line(str, &i)) < 0)
			return (0);
		if (str[i] == '\0')
		{
			params->r = 1;
			return (1);
		}
	}
	return (0);
}

static int	parse_params_path(char *str, char **dst, int *f)
{
	int		i;
	int		fd;

	i = 2;
	ft_skip_spaces(str, &i);
	if (!validate_filename(&str[i], "xpm"))
		handle_error(-5);
	if ((fd = open(&str[i], O_RDONLY)) > 0)
	{
		close(fd);
		if (!(*dst = ft_strdup(&str[i])))
			handle_error(-1);
		*f = 1;
		return (1);
	}
	return (0);
}

static int	get_params(char *tmp, t_params *params)
{
	if (tmp[0] == 'R' && params->r == 0)
		return (parse_params_r(tmp, params));
	else if (tmp[0] == 'N' && tmp[1] == 'O')
		return (parse_params_path(tmp, &params->no_path, &params->no));
	else if (tmp[0] == 'S' && tmp[1] == 'O')
		return (parse_params_path(tmp, &params->so_path, &params->so));
	else if (tmp[0] == 'W' && tmp[1] == 'E')
		return (parse_params_path(tmp, &params->we_path, &params->we));
	else if (tmp[0] == 'E' && tmp[1] == 'A')
		return (parse_params_path(tmp, &params->ea_path, &params->ea));
	else if (tmp[0] == 'S')
		return (parse_params_path(tmp, &params->s_path, &params->s));
	else if (tmp[0] == 'F')
		return (parse_params_color(tmp, &params->f_col, &params->f));
	else if (tmp[0] == 'C')
		return (parse_params_color(tmp, &params->c_col, &params->c));
	return (0);
}

int			parse_params(t_list **head, t_params *params)
{
	t_list	*tmp_list;
	int		i;
	int		count;
	char	*tmp;
	int		buf;

	i = 0;
	count = 0;
	while ((*head) != NULL && !check_is_map((*head)->content))
	{
		buf = 0;
		tmp = (*head)->content;
		if (ft_strlen(tmp) != 0 && !(buf = get_params(tmp, params)))
			force_list_del(head, -9, params);
		count += buf;
		tmp_list = (*head)->next;
		ft_lstdelone(*head, &free_line);
		*head = tmp_list;
	}
	if (count == 0 && (*head) == NULL)
		handle_error(-10);
	return ((count == 8 && params->r && params->no && params->so && params->we
		&& params->ea && params->s && params->f && params->c) ? 1 : 0);
}
