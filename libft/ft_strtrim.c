/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:01:30 by memilio           #+#    #+#             */
/*   Updated: 2020/05/08 14:34:24 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isinset(char c, const char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		++set;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	len = 0;
	while (ft_isinset(*s1, set))
		++s1;
	if (*s1)
	{
		len = ft_strlen(s1);
		while (ft_isinset(s1[len - 1], set))
			--len;
	}
	return (ft_substr(s1, 0, len));
}
