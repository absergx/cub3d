/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 05:04:07 by memilio           #+#    #+#             */
/*   Updated: 2020/05/07 00:36:11 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	char	*res;
	size_t	len;

	len = ft_strlen(src) + 1;
	res = (char *)malloc(sizeof(char) * len);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, src, len);
	return (res);
}
