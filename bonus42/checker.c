/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:37:13 by tbabayan          #+#    #+#             */
/*   Updated: 2022/05/23 19:06:21 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker.h"

static void	compare(char *line, t_list **a, t_list **b)
{
	if (!ft_strcmp(line, "ra\n"))
		ra(a, 0);
	if (!ft_strcmp(line, "rb\n"))
		rb(b, 0);
	if (!ft_strcmp(line, "rr\n"))
		rr(a, b, 0);
	if (!ft_strcmp(line, "rra\n"))
		rra(a, 0);
	if (!ft_strcmp(line, "rrb\n"))
		rrb(b, 0);
	if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, 0);
	if (!ft_strcmp(line, "sa\n"))
		sa(a, 0);
	if (!ft_strcmp(line, "sb\n"))
		sb(b, 0);
	if (!ft_strcmp(line, "ss\n"))
		ss(a, b, 0);
	if (!ft_strcmp(line, "pa\n"))
		pa(b, a, 0);
	if (!ft_strcmp(line, "pb\n"))
		pb(a, b, 0);
}

static void	gnl(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		compare(line, a, b);
		line = get_next_line(0);
	}
	if (!is_sorted(*a) || *b != NULL)
		write (1, "KO\n", 3);
	else
		write (1, "OK\n", 3);
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

char	**join_and_split(char **argv, int argc)
{
	char	*str;
	int		i;
	char	**array;

	i = 0;
	str = "\0";
	if (argv[1][0] == '\0')
	{
		write (2, "Error\n", 6);
		exit (0);
	}
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
	gnl(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
