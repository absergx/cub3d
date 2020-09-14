/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:23:07 by memilio           #+#    #+#             */
/*   Updated: 2020/09/12 13:43:41 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_max_str(t_list *head)
{
	int		res;
	int		len;

	res = 0;
	while (head)
	{
		if ((len = ft_strlen(head->content)) > res)
			res = len;
		head = head->next;
	}
	return (res);
}

static int	alloc_map(t_all *all)
{
	int		i;

	i = 0;
	if (!(all->map.map = (char **)malloc(sizeof(char *) * all->map.y_max + 1)))
		return (0);
	while (i < all->map.y_max)
	{
		all->map.map[i] = (char *)malloc(sizeof(char) * all->map.x_max + 1);
		if (all->map.map[i] == NULL)
			return (0);
		i++;
	}
	all->map.map[all->map.y_max] = NULL;
	return (1);
}

static void	add_spaces_to_map(t_all *all, int i, int y)
{
	while (i < all->map.x_max)
	{
		all->map.map[y][i] = ' ';
		i++;
	}
	all->map.map[y][i] = '\0';
}

int			make_map(t_list **head, t_all *all)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	all->map.x_max = find_max_str(*head);
	all->map.y_max = ft_lstsize(*head);
	if (!alloc_map(all))
		free_map(all->map.map, -1, head, &all->params);
	tmp = *head;
	while (tmp)
	{
		j = -1;
		while (((char *)tmp->content)[++j] != '\0')
			all->map.map[i][j] = ((char *)tmp->content)[j];
		if (j == 0 && i != all->map.y_max - 1)
			free_map(all->map.map, -13, head, &all->params);
		add_spaces_to_map(all, j, i);
		tmp = tmp->next;
		++i;
	}
	ft_lstclear(head, &free_line);
	return (1);
}

t_list		*parse_map(char *filename)
{
	t_list	*head;
	t_list	*tmp;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		handle_error(-3);
	line = NULL;
	head = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(tmp = ft_lstnew(line)))
			force_list_del(&head, -1, NULL);
		ft_lstadd_back(&head, tmp);
	}
	if (!(tmp = ft_lstnew(line)))
		force_list_del(&head, -1, NULL);
	ft_lstadd_back(&head, tmp);
	close(fd);
	return (head);
}
