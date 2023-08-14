/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:39:38 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/14 19:16:38 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	if (a -> size > 1)
	{
		push_d(a, pop_u(a));
		printf("ra\n");
	}
}

void	rb(t_stack *b)
{
	if (b -> size > 1)
	{
		push_d(b, pop_u(b));
		printf("rb\n");
	}
}

void	rr(t_stack *a, t_stack *b)
{
	if (a -> size > 1)
		push_d(a, pop_u(a));
	if (b -> size > 1)
		push_d(b, pop_u(b));
	if (a -> size > 1 || b -> size > 1)
		printf("rr\n");
}

int	ft_atoi(const char *str)
{
	int			minus;
	long long	num;

	num = 0;
	minus = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -minus;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (minus * (int)num);
}