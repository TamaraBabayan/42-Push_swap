/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:22:26 by tbabayan          #+#    #+#             */
/*   Updated: 2022/05/21 15:03:23 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	rotate_(t_list **st)
{
	t_list	*temp;

	temp = (*st);
	if (st)
	{
		last_node(*st)->next = temp;
		*st = (*st)->next;
		temp -> next = NULL;
	}
}

void	ra(t_list **a, int k)
{
	rotate_(a);
	if (k == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **b, int k)
{
	rotate_(b);
	if (k == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, int k)
{
	rotate_(a);
	rotate_(b);
	if (k == 1)
		write(1, "rr\n", 3);
}
