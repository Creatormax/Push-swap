/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:33:51 by hmorales          #+#    #+#             */
/*   Updated: 2022/12/20 12:27:16 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_list *a, t_list *b)
{
	a = ft_lstfirst(a);
	b = ft_lstfirst(b);
	while (a != NULL)
	{
		printf("A :%d\n", ((t_stack *)(a)->content)->num);
		a = a->next;
	}
	printf("\n");
	while (b != NULL)
	{
		printf("B :%d\n", ((t_stack *)(b)->content)->num);
		b = b->next;
	}
	printf("\n");
}

int	is_sorted(int mid, t_list *a)
{
	int	chk;

	chk = 1;
	a = ft_lstfirst(a);
	while (a->next)
	{
		if (((t_stack *)(a)->content)->num < mid)
		{
			chk = 0;
			return (chk);
		}
		a = a->next;
	}
	//printf("%d", chk);
	return (chk);
}

void	parse(char *str)
{
	int	num;

	num = 0;
	num = ft_atoi(str);
	if (num > 2147483647 || num < -2147483648)
		ft_errormsg("Int overflow detected");
}
