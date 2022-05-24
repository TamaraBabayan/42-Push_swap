/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:20:11 by tbabayan          #+#    #+#             */
/*   Updated: 2022/05/21 15:02:56 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	push_(t_list **st1, t_list **st2)
{
	t_list	*temp;

	temp = *st1;
	*st1 = (*st1)->next;
	push_front(st2, temp);
}

void	pa(t_list **b, t_list **a, int k)
{
	if (b == NULL)
		return ;
	push_(b, a);
	if (k == 1)
		write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b, int k)
{
	if (a == NULL)
		return ;
	push_(a, b);
	if (k == 1)
		write(1, "pb\n", 3);
}
