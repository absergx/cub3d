/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:08:58 by memilio           #+#    #+#             */
/*   Updated: 2020/05/03 14:32:22 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int symbol)
{
	int i;

	i = 0;
	while (string[i] != '\0')
		++i;
	while (i >= 0)
	{
		if (string[i] == symbol)
			return ((char *)(string + i));
		--i;
	}
	return (NULL);
}
