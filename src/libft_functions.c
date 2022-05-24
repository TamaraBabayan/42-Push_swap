/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:49:21 by tbabayan          #+#    #+#             */
/*   Updated: 2022/05/21 16:11:18 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (dstsize == 0)
		return (len);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	if (!s)
		return (0);
	while (s[c] != '\0')
		c++;
	return (c);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	char	*s;

	newstring = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s2 || !newstring)
		return (NULL);
	s = newstring;
	while (*s1)
	{
		*newstring = *s1;
		newstring++;
		s1++;
	}
	while (*s2)
	{
		*newstring = *s2;
		newstring++;
		s2++;
	}
	*newstring = '\0';
	return (s);
}

static int	is(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

long int	ft_atoilong(const char *str)
{
	long int	a;
	int			n;

	a = 0;
	n = 1;
	while (is(*str, "\t\n\v\f\r "))
		str++;
	if (*str == '-')
	{
		n = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		a *= 10;
		a += *str - 48;
		str++;
	}
	if (in_range(n * a) == 0)
	{
		return (-9999999999);
	}
	return (n * a);
}
