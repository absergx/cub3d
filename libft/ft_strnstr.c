/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:08:22 by memilio           #+#    #+#             */
/*   Updated: 2020/05/03 14:32:22 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t size)
{
	size_t i;
	size_t k;

	if (*str2 == '\0')
		return ((char *)str1);
	i = 0;
	while (str1[i] != '\0' && i < size)
	{
		k = 0;
		while (str2[k] != '\0' && str1[i + k] == str2[k] && str1[i + k] != '\0'
			&& i + k < size)
			++k;
		if (str2[k] == '\0')
			return ((char *)(str1 + i));
		++i;
	}
	return (NULL);
}
