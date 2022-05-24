/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pushes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:20:11 by tbabayan          #+#    #+#             */
/*   Updated: 2022/05/23 19:02:00 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	push_(t_list **st1, t_list **st2)
{
	t_list	*temp;

	if (stack_size(*st1) != 0)
	{
		temp = *st1;
		*st1 = (*st1)->next;
		push_front(st2, temp);
	}
}

void	pa(t_list **b, t_list **a, int k)
{
	push_(b, a);
	if (k == 1)
		write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b, int k)
{
	push_(a, b);
	if (k == 1)
		write(1, "pb\n", 3);
}

void	ft_fill_stack(t_list **stack, char **res)
{
	int		i;
	t_list	*node;

	i = 0;
	while (res[i])
	{
		node = create_stack_node((int)ft_atoilong(res[i]));
		push_back(stack, node);
		i++;
	}
}
