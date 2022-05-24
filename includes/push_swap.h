/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:17:03 by tbabayan          #+#    #+#             */
/*   Updated: 2022/05/21 18:31:43 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				info;
	struct s_list	*next;
	int				index;
}					t_list;

t_list	*create_stack_node(int content);
t_list	*last_node(t_list *stack);
void	push_back(t_list **stack, t_list *node);
void	push_front(t_list **stack, t_list *node);
int		stack_size(t_list *stack);
char	**join_and_split(char **argv, int argc);
int		checking(char *str);
int		index_of_min(t_list *a);
void	ft_fill_stack(t_list **stack, char **res);

void	ft_free_stack(t_list **st);
void	ft_free_str(char **str);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
int		in_range(long int num);
int		no_alpha(char *str);
int		ft_strcmp(char *s1, char *s2);
int		no_doubles(char **array, char *str, int pos);
long	ft_atoilong(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

int		is_sorted(t_list *a);
void	sort_stack(t_list **a, t_list **b);
void	sort_three(t_list **a);
void	sort_four(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b);
void	indexing(t_list **a);
t_list	*next_min(t_list *a);
void	main_radix_sort(t_list **a, t_list **b);
int		lenght_of_max(t_list **a);

void	sa(t_list **a, int k);
void	sb(t_list **b, int k);
void	ss(t_list **a, t_list **b, int k);

void	pa(t_list **b, t_list **a, int k);
void	pb(t_list **a, t_list **b, int k);

void	ra(t_list **a, int k);
void	rb(t_list **b, int k);
void	rr(t_list **a, t_list **b, int k);

void	rra(t_list **a, int k);
void	rrb(t_list **b, int k);
void	rrr(t_list **a, t_list **b, int k);

#endif
