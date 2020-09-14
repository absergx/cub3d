/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 01:45:44 by memilio           #+#    #+#             */
/*   Updated: 2020/05/06 18:55:56 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *head;
	t_list *tail;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	tmp = lst;
	if (!(head = ft_lstnew((*f)(tmp->content))))
		return (NULL);
	tail = head;
	tmp = tmp->next;
	while (tmp)
	{
		if (!(tail->next = ft_lstnew((*f)(tmp->content))))
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		tail = tail->next;
		tmp = tmp->next;
	}
	return (head);
}
