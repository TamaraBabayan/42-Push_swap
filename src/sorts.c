/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:48:38 by tbabayan          #+#    #+#             */
/*   Updated: 2022/05/21 15:05:37 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	is_sorted(t_list *a)
{
	while (a -> next)
	{
		if (a -> info > a -> next -> info)
			return (0);
		a = a -> next;
	}
	return (1);
}

void	sort_three(t_list **a)
{
	if ((*a)->info < (*a)->next -> info)
	{
		rra(a, 1);
		if (is_sorted(*a) == 0)
			sa(a, 1);
	}
	else if ((*a)->info > (*a)->next -> info)
	{
		if ((*a)->info < (*a)->next -> next -> info)
			sa(a, 1);
		else
		{
			ra(a, 1);
			if (!is_sorted(*a))
				sa(a, 1);
		}
	}
}

void	sort_four(t_list **a, t_list **b)
{
	int	i;

	i = index_of_min(*a);
	if (i == 1)
		sa(a, 1);
	else if (i == 2)
	{
		rra(a, 1);
		rra(a, 1);
	}
	else if (i == 3)
		rra(a, 1);
	if (is_sorted(*a))
		return ;
	pb(a, b, 1);
	sort_three(a);
	pa(b, a, 1);
}

void	sort_five(t_list **a, t_list **b)
{
	int	i;

	i = index_of_min(*a);
	if (i == 1)
		sa(a, 1);
	else if (i == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (i == 3)
	{
		rra(a, 1);
		rra(a, 1);
	}
	else if (i == 4)
		rra(a, 1);
	if (is_sorted(*a))
		return ;
	pb(a, b, 1);
	sort_four(a, b);
	pa(b, a, 1);
}

void	sort_stack(t_list **a, t_list **b)
{
	(void)b;
	if (stack_size(*a) == 2)
		sa(a, 1);
	if (stack_size(*a) == 3)
		sort_three(a);
	if (stack_size(*a) == 4)
		sort_four(a, b);
	if (stack_size(*a) == 5)
		sort_five(a, b);
	if (stack_size(*a) > 5)
		main_radix_sort(a, b);
}
