/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:13:55 by hmorales          #+#    #+#             */
/*   Updated: 2022/12/20 15:21:07 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **a)
{
	int	copy;

	if (ft_lstsize(*a) < 2)
		return;
	copy = ((t_stack *)(*a)->content)->num;
	((t_stack *)(*a)->content)->num = ((t_stack *)(*a)->next->content)->num;
	((t_stack *)(*a)->next->content)->num = copy;
	*a = ft_lstfirst(*a);
}

void	push(t_list **src, t_list **dest)
{
	t_list	*copy;

	copy = ft_lstfirst(*src);
	if (*src != NULL)
	{
		ft_lstadd_front(dest, ft_lstnew(copy->content));
		*src = copy->next;
		if (ft_lstsize(*src) != 0)
		{
			free((*src)->prior);
			(*src)->prior = NULL;
		}
		else
			free(copy);
	}
	*src = ft_lstfirst(*src);
	*dest = ft_lstfirst(*dest);
}

void	rotate(t_list **a)
{
	t_list	*copy;

	if (ft_lstsize(*a) < 2)
		return;
	copy = ft_lstlast(*a);
	copy->next = *a;
	(*a)->prior = copy;
	(*a)->next->prior = NULL;
	(*a)->next = NULL;
	*a = ft_lstfirst(*a);
}

void	rev_rotate(t_list **a)
{
	t_list	*copy;

	if (ft_lstsize(a) < 2)
		return;
	copy = ft_lstlast(*a);
	copy->next = *a;
	(*a)->prior = copy;
	copy->prior->next = NULL;
	copy->prior = NULL;
	*a = ft_lstfirst(*a);
}
