/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_case1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:28:09 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/21 19:18:10 by seonjo           ###   ########.fr       */
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

void	sort_three_rvs(t_stack *b)
{
	int	x;
	int	y;
	int	z;

	x = peek_top(b, 1);
	y = peek_top(b, 2);
	z = peek_bot(b, 1);
	if (x > y && y < z && z > x)
		rrb(b);
	else if (x < y && y < z && x < z)
	{
		sb(b);
		rrb(b);
	}
	else if (x > y && x > z && z > y)
	{
		rrb(b);
		sb(b);
	}
	else if (x < y && x < z && y > z)
		rb(b);
	else if (x < y && x > z && y > z)
		sb(b);
}

static void	sort_eight(t_stack *a, t_stack *b)
{
	int	an;
	int	bn;

	pb(a, b);
	pb(a, b);
	pb(a, b);
	sort_three_rvs(b);
	sort_five(a, b);
	an = 5;
	bn = 3;
	while (an > 0 || bn > 0)
	{
		if (an == 0 || (bn != 0 && peek_bot(a, 1) < peek_top(b, 1)))
		{
			pa(a, b);
			bn--;
		}
		else
		{
			rra(a);
			an--;
		}
	}
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
	else if (a -> size == 8)
		sort_eight(a, b);
	else
		return ;
	exit(0);
}
