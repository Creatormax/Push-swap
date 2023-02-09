/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:18:33 by hmorales          #+#    #+#             */
/*   Updated: 2023/02/09 20:01:32 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]) == 1)
			ft_errormsg("There must be no letters in the stack");
		if ((str[i] > '9' || str[i] < '0') && str[i] != '+' && str[i] != '-')
			ft_errormsg("There are not permited characters");
		if (i != 0 && (str[i] == '+' || str[i] == '-'))
			ft_errormsg("There is a missuse in characters");
		i++;
	}
}	

t_list	**savedata(int argc, char **argv, t_list **a, t_list **copy)
{
	char	**str;
	int		i;
	int		j;
	t_stack	*num;
	t_stack	*numcpy;

	i = 1;
	num = NULL;
	numcpy = NULL;
	while (i < argc)
	{
		str = ft_split((argv[i++]), ' ');
		j = 0;
		while (str[j])
		{
			num = malloc(sizeof(t_stack));
			num->num = ft_atoi(str[j]);
			ft_lstadd_back(a, ft_lstnew(num));
			numcpy = malloc(sizeof(t_stack));
			numcpy->num = ft_atoi(str[j++]);
			ft_lstadd_back(copy, ft_lstnew(numcpy));
		}
		ft_liberator(str);
	}
	return (a);
}

int	duplicates(t_list *a)
{
	while (a && a->next)
	{
		if (((t_stack *)(a)->content)->num == \
		((t_stack *)(a)->next->content)->num)
			return (1);
		a = (a)->next;
	}
	return (0);
}

t_list	*initializer(int argc, char **argv, t_list **a, t_list **copy)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		checker(argv[i]);
		parse(argv[i]);
		i++;
	}
	a = savedata(argc, argv, a, copy);
	if (duplicates(*a) == 1)
	{
		ft_lstclear(&(*a), free);
		ft_errormsg("There are duplicates in the stack");
	}
	return (*a);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*copy;

	a = NULL;
	b = NULL;
	copy = NULL;
	if (argc < 2)
		ft_errormsg("Please submit a stack");
	a = initializer(argc, argv, &a, &copy);
	print_stacks(a, b);
	process(&a, &b);
	//print_stacks(a, b);
}
