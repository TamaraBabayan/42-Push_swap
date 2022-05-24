/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_radix_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:55:54 by tbabayan          #+#    #+#             */
/*   Updated: 2022/05/21 15:46:46 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	main_radix_sort(t_list **a, t_list **b)
{
	int		i;
	int		size;
	int		j;
	int		max_index_lenght;

	i = 0;
	size = stack_size(*a);
	indexing(a);
	max_index_lenght = lenght_of_max(a);
	while (i < max_index_lenght)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a, 1);
			else
				pb(a, b, 1);
			j++;
		}
		while (stack_size(*b))
			pa(b, a, 1);
		i++;
	}
}

int	lenght_of_max(t_list **a)
{
	int	max;
	int	i;
	int	tmp;

	i = 1;
	tmp = 2;
	max = stack_size(*a) - 1;
	while (tmp <= max)
	{
		tmp *= 2;
		i++;
	}
	return (i);
}

t_list	*next_min(t_list *a)
{
	int		first;
	t_list	*node;
	t_list	*min_node;

	min_node = NULL;
	first = 0;
	node = a;
	while (node)
	{
		if (node -> index == -1 && (first == 0
				|| node -> info < min_node -> info))
		{
			first = 1;
			min_node = node;
		}
		node = node -> next;
	}
	return (min_node);
}

void	indexing(t_list **a)
{
	t_list	*top;
	int		index;

	index = 0;
	top = next_min(*a);
	while (top)
	{
		top -> index = index;
		index++;
		top = next_min(*a);
	}
}
