/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_checks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:53:07 by tbabayan          #+#    #+#             */
/*   Updated: 2022/05/23 18:34:53 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	in_range(long int num)
{
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}

int	no_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+' || str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (i == 1 && (*str == '+' || *str == '-'))
		return (0);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	no_doubles(char **array, char *str, int pos)
{
	int	i;

	i = 0;
	while (i != pos)
	{
		if (ft_strcmp(array[i], str) == 0)
			return (0);
		i++;
	}
	return (1);
}

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
