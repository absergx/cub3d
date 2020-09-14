/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 15:56:23 by memilio           #+#    #+#             */
/*   Updated: 2020/08/11 14:36:07 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_memclean(char *buffer, char *surplus)
{
	if (buffer)
		free(buffer);
	if (surplus)
		free(surplus);
	return (-1);
}

static int		check_errors(char **line, char **surplus, int bytes)
{
	if (!bytes && !(*surplus))
	{
		if (!(*line = ft_strdup_gnl("", 0)))
			return (-1);
		return (0);
	}
	if (bytes < 0)
	{
		if (*surplus)
		{
			free(*surplus);
			*surplus = NULL;
		}
		return (-1);
	}
	return (1);
}

static int		check_result(char **line, char **surplus, int bytes)
{
	char		*tmp;
	char		*new_surplus;
	int			errors;

	if ((errors = check_errors(line, surplus, bytes)) < 1)
		return (errors);
	if ((tmp = ft_strchr(*surplus, '\n')))
	{
		*tmp = '\0';
		if (!(new_surplus = ft_strdup_gnl((tmp + 1), 0)))
			return (ft_memclean(NULL, *surplus));
		if (!(*line = ft_strdup_gnl(*surplus, 1)))
			return (ft_memclean(new_surplus, *surplus));
		*surplus = new_surplus;
		return (1);
	}
	else if (ft_strchr(*surplus, '\0'))
	{
		if (!(*line = ft_strdup_gnl(*surplus, 1)))
			return (ft_memclean(NULL, *surplus));
		*surplus = NULL;
	}
	return (0);
}

static char		*new_surplus(char *surplus, char *buffer)
{
	char	*new_surplus;

	if (!surplus)
		return (ft_strdup_gnl(buffer, 0));
	else
	{
		new_surplus = ft_strjoin(surplus, buffer);
		free(surplus);
		return (new_surplus);
	}
}

int				get_next_line(int fd, char **line)
{
	static char	*surplus = NULL;
	char		*buffer;
	int			bytes;

	if (fd < 0 || !line || BUFFER_SIZE < 1 ||
		!(buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes] = '\0';
		if (!(surplus = new_surplus(surplus, buffer)))
			return (ft_memclean(buffer, surplus));
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	ft_memclean(buffer, NULL);
	return (check_result(line, &surplus, bytes));
}
