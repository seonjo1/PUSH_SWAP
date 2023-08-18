/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:18:46 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/18 19:26:05 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	is_null(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		error();
	while (arr[i] != NULL)
		i++;
	if (i == 0)
		error();
}

static int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		else if (!*str1 && !*str2)
			return (0);
		str1++;
		str2++;
		n--;
	}
	return (0);
}

int	ft_strlen(char	*man)
{
	int	i;

	i = 0;
	while (man[i] != '\0')
		i++;
	return (i);
}

void	execute(t_stack *a, t_stack *b, char *man, int len)
{
	if (ft_strncmp("sa\n", man, len) == 0)
		sa(a);
	else if (ft_strncmp("sb\n", man, len) == 0)
		sb(b);
	else if (ft_strncmp("ss\n", man, len) == 0)
		ss(a, b);
	else if (ft_strncmp("pa\n", man, len) == 0)
		pa(a, b);
	else if (ft_strncmp("pb\n", man, len) == 0)
		pb(a, b);
	else if (ft_strncmp("ra\n", man, len) == 0)
		ra(a);
	else if (ft_strncmp("rb\n", man, len) == 0)
		rb(b);
	else if (ft_strncmp("rr\n", man, len) == 0)
		rr(a, b);
	else if (ft_strncmp("rra\n", man, len) == 0)
		rra(a);
	else if (ft_strncmp("rrb\n", man, len) == 0)
		rrb(b);
	else if (ft_strncmp("rrr\n", man, len) == 0)
		rrr(a, b);
	else
		error();
}
