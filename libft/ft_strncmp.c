/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 00:22:24 by memilio           #+#    #+#             */
/*   Updated: 2020/05/03 14:32:23 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t size)
{
	size_t i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && i < size)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		++i;
	}
	if (str1[i] != str2[i] && i != size)
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	return (0);
}
