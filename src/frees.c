/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:39:27 by tbabayan          #+#    #+#             */
/*   Updated: 2022/05/12 16:45:06 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(*str);
		i++;
	}
	free(str);
}

void	ft_free_stack(t_list **st)
{
	t_list	*front;
	t_list	*tmp;

	tmp = *st;
	while (tmp)
	{
		front = tmp;
		tmp = tmp -> next;
		free(front);
	}
	free(st);
}
