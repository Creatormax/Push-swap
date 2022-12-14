/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:13:55 by hmorales          #+#    #+#             */
/*   Updated: 2022/12/14 16:41:39 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **a)
{
	int	copy;

	if (!a || !(t_stack *)(*a)->content || !(t_stack *)(*a)->next->content)
		ft_errormsg("List not pushed");
	*a = ft_lstfirst(*a);
	copy = ((t_stack *)(*a)->content)->num;
	((t_stack *)(*a)->content)->num = ((t_stack *)(*a)->next->content)->num;
	((t_stack *)(*a)->next->content)->num = copy;
}

void	push(t_list **pushed, t_list **put)
{
	t_list	*copy;

	*pushed = ft_lstfirst(*pushed);
	*put = ft_lstfirst(*put);
	copy = *pushed;
	if ((*pushed)->content != NULL)
	{
		ft_lstadd_front(put, ft_lstnew((int *)((*pushed)->content)));
		if (ft_lstsize(*pushed) <= 1)
			(*pushed)->content = NULL;
		else
		{
			*pushed = (*pushed)->next;
			free (copy);
			copy = NULL;
		}
	}
}

void	rotate(t_list **a)
{
	t_list	*copy;
	int		i;

	i = ft_lstsize(*a);
	copy = ft_lstlast(*a);
	copy->next = *a;
	while (i-- > 0)
	{
		
	}
	
}

void	rev_rotate(t_list **a)
{
	*a = ft_lstfirst(*a);
}
