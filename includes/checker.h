/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:21:17 by tbabayan          #+#    #+#             */
/*   Updated: 2022/05/21 19:03:05 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				info;
	struct s_list	*next;
	int				index;
}					t_list;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**join_and_split(char **argv, int argc);
void	ft_fill_stack(t_list **stack, char **res);
int		checking(char *str);

char	*ft_strjoinfree(char *saved, char *buffer);
int		ft_strlen_n(char *saved);
char	*ft_edit(char **saved);
char	*ft_read(int fd, char **saved, char *line);
int		ft_strcmp(char *s1, char *s2);
long	ft_atoilong(const char *str);
int		is_sorted(t_list *a);

void	push_back(t_list **stack, t_list *node);
t_list	*create_stack_node(int content);
t_list	*last_node(t_list *stack);
void	push_front(t_list **stack, t_list *node);
int		stack_size(t_list *stack);

void	ft_free_str(char **str);
void	ft_free_stack(t_list **st);
char	**ft_split(char const *s, char c);
int		in_range(long int num);
int		no_alpha(char *str);
int		ft_strcmp(char *s1, char *s2);
int		no_doubles(char **array, char *str, int pos);

void	pa(t_list **b, t_list **a, int k);
void	pb(t_list **a, t_list **b, int k);

void	rra(t_list **a, int k);
void	rrb(t_list **b, int k);
void	rrr(t_list **a, t_list **b, int k);

void	ra(t_list **a, int k);
void	rb(t_list **b, int k);
void	rr(t_list **a, t_list **b, int k);

void	sa(t_list **a, int k);
void	sb(t_list **b, int k);
void	ss(t_list **a, t_list **b, int k);

#endif
