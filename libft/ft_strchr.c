/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:08:35 by memilio           #+#    #+#             */
/*   Updated: 2020/05/03 14:32:27 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	while (*string != '\0')
	{
		if (symbol == *string)
			return ((char *)string);
		++string;
	}
	if (symbol == *string)
		return ((char *)string);
	return (NULL);
}
