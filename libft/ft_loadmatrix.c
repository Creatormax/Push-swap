/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadmatrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:44:41 by hmorales          #+#    #+#             */
/*   Updated: 2022/10/05 15:27:05 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_loadmatrix(int data, int *matrix)
{
	int	a;

	a = 0;
	while (a)
	{
		matrix[a] = data;
		a++;
	}
}
