/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:31:29 by tbabayan          #+#    #+#             */
/*   Updated: 2022/05/18 17:22:36 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	index_of_min(t_list *a)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	index = 0;
	min = a -> info;
	while (a)
	{
		if (a -> info < min)
		{
			min = a -> info;
			index = i;
		}
		i++;
		a = a -> next;
	}
	return (index);
}
