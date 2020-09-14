/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 01:33:57 by memilio           #+#    #+#             */
/*   Updated: 2020/05/03 14:32:29 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putlong_fd(long num, int fd)
{
	if (num >= 10)
		ft_putlong_fd((num / 10), fd);
	ft_putchar_fd((num % 10 + '0'), fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	long num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	ft_putlong_fd(num, fd);
}
