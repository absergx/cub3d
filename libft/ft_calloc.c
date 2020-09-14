/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 04:47:33 by memilio           #+#    #+#             */
/*   Updated: 2020/05/08 14:17:10 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	len;
	size_t	i;

	len = count * size;
	if (!(res = malloc(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		((unsigned char *)res)[i] = 0;
		++i;
	}
	return (res);
}
