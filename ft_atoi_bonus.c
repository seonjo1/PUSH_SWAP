/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:18:50 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 21:41:05 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	*pass_white_space(char	*str)
{
	while (*str >= 9 && *str <= 13)
		str++;
	return (str);
}

static char	*sign_check(char *str, int *minus)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*minus = *minus * -1;
		str++;
	}
	return (str);
}

static int	overflow_check(long long num, long long i)
{
	if (i > 10)
		error();
	if (num < -2147483648 || num > 2147483647)
		error();
	return ((int) num);
}

int	ft_atoi(char *str)
{
	int			minus;
	long long	i;
	long long	num;

	i = 0;
	num = 0;
	minus = 1;
	str = pass_white_space(str);
	str = sign_check(str, &minus);
	if (!(*str >= '0' && *str <= '9'))
		error();
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
		if (num > 0)
			i++;
	}
	str = pass_white_space(str);
	if (*str != '\0')
		error();
	return (overflow_check(num * minus, i));
}
