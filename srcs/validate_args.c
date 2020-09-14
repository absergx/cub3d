/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:52:35 by memilio           #+#    #+#             */
/*   Updated: 2020/09/13 12:38:27 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			validate_filename(char *filename, char *ext)
{
	int len;

	if ((len = ft_strlen(filename)) > 4 &&
		filename[len - 1] == ext[2] && filename[len - 2] == ext[1] &&
		filename[len - 3] == ext[0] && filename[len - 4] == '.')
		return (1);
	if (ext != NULL && ext[0] == 'c')
		handle_error(-4);
	return (0);
}

static char	*validate_args(int argc, char **argv, t_all *all)
{
	if (argc == 1)
		free_all(all, -7);
	else if (argc == 3)
	{
		if (!(ft_strncmp("--save", argv[2], 6))
			&& validate_filename(argv[1], "cub"))
		{
			all->screenshot = 1;
			return (argv[1]);
		}
		else
			free_all(all, -6);
	}
	else if (argc == 2 && validate_filename(argv[1], "cub"))
		return (argv[1]);
	else
		free_all(all, -8);
	return (NULL);
}

int			total_validate(t_all *all, int argc, char **argv)
{
	char	*filename;
	t_list	*head;

	if ((filename = validate_args(argc, argv, all)))
	{
		head = parse_map(filename);
		if (!parse_params(&head, &(all->params)))
			force_list_del(&head, -9, NULL);
		if (make_map(&head, all))
			return (validate_map(all));
	}
	return (0);
}
