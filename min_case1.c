/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_case1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:28:09 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 14:41:14 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (peek_top(a, 1) > peek_top(a, 2))
		sa(a);
}

void	sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = peek_top(a, 1);
	y = peek_top(a, 2);
	z = peek_bot(a, 1);
	if (x > y && x < z && y < z)
		sa(a);
	else if (x > y && x > z && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && x > z && y < z)
		ra(a);
	else if (x < y && x < z && y > z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && x > z && y > z)
		rra(a);
}

void	min_case(t_stack *a, t_stack *b)
{
	if (a -> size == 2)
		sort_two(a);
	else if (a -> size == 3)
		sort_three(a);
	else if (a -> size == 4)
		sort_four(a, b);
	else if (a -> size == 5)
		sort_five(a, b);
	else if (a -> size == 6)
		sort_six(a, b);
	else if (a -> size == 7)
		sort_seven(a, b);
	else
		return ;
	exit(0);
}
