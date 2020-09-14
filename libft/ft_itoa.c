/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 22:52:56 by memilio           #+#    #+#             */
/*   Updated: 2020/05/03 14:32:38 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(long n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	size_t	f;
	long	tmp;

	f = 0;
	tmp = n;
	len = ft_numlen(tmp);
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (tmp < 0)
	{
		tmp = -tmp;
		res[0] = '-';
		f = 1;
	}
	res[len] = '\0';
	while ((len - f) > 0)
	{
		res[len - 1] = tmp % 10 + '0';
		tmp /= 10;
		--len;
	}
	return (res);
}
