/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_swaps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:18:40 by tbabayan          #+#    #+#             */
/*   Updated: 2022/05/23 19:05:18 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	swap_(t_list **op)
{
	int	temp;

	if (stack_size(*op) != 0)
	{
		if (op)
		{
			temp = (*op)->info;
			(*op)->info = (*op)->next->info;
			(*op)->next->info = temp;
		}
	}
}

void	sa(t_list **a, int k)
{
	swap_(a);
	if (k == 1)
		write(1, "sa\n", 3);
}

void	sb(t_list **b, int k)
{
	swap_(b);
	if (k == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, int k)
{
	swap_(a);
	swap_(b);
	if (k == 1)
		write(1, "s\n", 3);
}
