/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 04:05:48 by memilio           #+#    #+#             */
/*   Updated: 2020/05/08 15:11:26 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *srct;
	unsigned char *dstt;

	if (src == dst || len == 0)
		return (dst);
	srct = (unsigned char *)src;
	dstt = (unsigned char *)dst;
	if (srct < dstt)
	{
		while (len)
		{
			--len;
			dstt[len] = srct[len];
		}
	}
	else
	{
		while (len)
		{
			--len;
			*dstt++ = *srct++;
		}
	}
	return (dst);
}
