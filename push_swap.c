/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:18:33 by hmorales          #+#    #+#             */
/*   Updated: 2022/09/21 17:03:16 by hmorales         ###   ########.fr       */
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

void	savedata(int argc, char **argv, t_list **a, t_list **copy)
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
}

int	duplicates(t_list **a)
{
	while (*a && (*a)->next)
	{
		if (((t_stack *)(*a)->content)->num == ((t_stack *)(*a)->next->content)->num)
			return (1);
		*a = (*a)->next;
	}
	return (0);
}

void	initializer(int argc, char **argv, t_list **a, t_list **copy)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		checker(argv[i]);
		i++;
	}
	savedata(argc, argv, a, copy);
	if (duplicates(a) == 1)
	{
		ft_lstclear(&(*a), free);
		ft_errormsg("There are duplicates in the stack");
	}
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
	initializer(argc, argv, &a, &copy);
	free(copy);
	while (a->prior)
		a = a->prior;
	while (a->content)
	{
		printf("%d\n", ((t_stack *)(a)->content)->num);
		if (a->next)
			a = a->next;
		else
			break;
	}
	printf("\n");
	b = ft_lstnew(malloc(sizeof(t_stack)));//inicializacion
	rev_rotate(a);
}
