/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:27:33 by memilio           #+#    #+#             */
/*   Updated: 2020/05/06 17:58:26 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_memclear(char **res)
{
	int i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		++i;
	}
	free(res);
	return (NULL);
}

static size_t	ft_wordscount(const char *s, char c)
{
	size_t i;
	size_t f;
	size_t count;

	count = 0;
	i = 0;
	f = 1;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (f == 1)
			{
				++count;
				f = 0;
			}
			++i;
		}
		else
		{
			f = 1;
			++i;
		}
	}
	return (count);
}

static size_t	ft_letterscount(const char *s, size_t i, char c)
{
	size_t	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		++i;
		++len;
	}
	return (len);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	if (!(res = (char **)malloc(sizeof(char *) * ft_wordscount(s, c) + 1)))
		return (NULL);
	while (j < ft_wordscount(s, c))
	{
		while (s[i] == c)
			++i;
		if (!(res[j] = ft_substr(s, i, ft_letterscount(s, i, c))))
			return (ft_memclear(res));
		while (s[i] != c && s[i] != '\0')
			++i;
		++j;
	}
	res[j] = NULL;
	return (res);
}
