/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrots.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:24:06 by tbabayan          #+#    #+#             */
/*   Updated: 2022/05/21 15:02:32 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	revrot_(t_list **st)
{
	t_list	*temp;
	t_list	*first;

	first = *st;
	temp = *st;
	if (st)
	{
		while (temp -> next -> next)
			temp = temp -> next;
		temp -> next -> next = first;
		*st = temp -> next;
		temp -> next = NULL;
	}
}

void	rra(t_list **a, int k)
{
	revrot_(a);
	if (k == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, int k)
{
	revrot_(b);
	if (k == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, int k)
{
	revrot_(a);
	revrot_(b);
	if (k == 1)
		write(1, "rrr\n", 4);
}
