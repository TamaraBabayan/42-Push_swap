/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:46:03 by tbabayan          #+#    #+#             */
/*   Updated: 2022/05/20 19:22:09 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

char	**join_and_split(char **argv, int argc)
{
	char	*str;
	int		i;
	char	**array;

	i = 0;
	str = "\0";
	while (++i != argc)
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " ");
	}
	if (checking(str) == 1)
	{
		array = ft_split(str, ' ');
		return (array);
	}
	return (0);
}

int	checking(char *str)
{
	char		**array;
	int			i;
	long int	num;

	i = 0;
	array = ft_split(str, ' ');
	while (array[i])
	{
		num = ft_atoilong(array[i]);
		if (!no_alpha(array[i]) || !no_doubles(array, array[i], i)
			|| !in_range(num))
		{
			write(2, "Error\n", 6);
			exit (0);
		}
		i++;
	}
	return (1);
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

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	char	**res;
	int		i;

	i = 0;
	if (argc < 2)
		return (0);
	a = (t_list **)malloc(sizeof(t_list *));
	b = (t_list **)malloc(sizeof(t_list *));
	*a = NULL;
	*b = NULL;
	res = join_and_split(argv, argc);
	ft_fill_stack(a, res);
	if (is_sorted(*a))
	{
		ft_free_stack(a);
		ft_free_stack(b);
		return (0);
	}
	sort_stack(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
