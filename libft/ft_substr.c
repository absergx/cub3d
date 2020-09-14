/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:04:38 by memilio           #+#    #+#             */
/*   Updated: 2020/05/08 16:15:34 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	len_sub;

	if (!s)
		return (NULL);
	len_sub = ft_strlen(s);
	if (len_sub < start)
		len = 0;
	else
	{
		len_sub -= start;
		if (len_sub < len)
			len = len_sub;
	}
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = ((char *)s)[start + i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
