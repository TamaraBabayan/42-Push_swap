/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:20:39 by tbabayan          #+#    #+#             */
/*   Updated: 2022/05/21 19:02:05 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_list	*create_stack_node(int content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	node -> info = content;
	node -> next = NULL;
	node -> index = -1;
	return (node);
}

t_list	*last_node(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack -> next)
		stack = stack -> next;
	return (stack);
}

void	push_back(t_list **stack, t_list *node)
{
	t_list	*back;

	if (node == NULL)
		return ;
	if (*stack)
	{
		back = last_node(*stack);
		back -> next = node;
		node -> next = NULL;
	}
	else
		*stack = node;
}

void	push_front(t_list **stack, t_list *node)
{
	if (node == NULL)
		return ;
	node -> next = *stack;
	*stack = node;
}

int	stack_size(t_list *stack)
{
	t_list	*node;
	int		count;

	count = 0;
	if (stack)
	{
		node = stack;
		while (node)
		{
			node = node -> next;
			count++;
		}
	}
	return (count);
}
