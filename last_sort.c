/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:25:12 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 14:26:03 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_rest1(t_stack *a, t_stack *b, int *group)
{
	if (group[0] > 0)
	{
		while (group[0]-- > 0)
		{
			rra(a);
			pb(a, b);
		}
	}
	if (group[1] > 0)
		while (group[1]-- > 0)
			pb(a, b);
}

static void	move_rest2(t_stack *a, t_stack *b, int *group)
{
	if (group[0] > 0)
	{
		while (group[0]-- > 0)
		{
			rrb(b);
			pa(a, b);
		}
	}
	if (group[1] > 0)
		while (group[1]-- > 0)
			pa(a, b);
}

static void	two_make_one_a(t_stack *a, t_stack *b, int *group)
{
	while (a -> size > 0 && group[0] > 0 && group[1] > 0)
	{
		if (peek_top(a, 1) > peek_bot(a, 1))
		{
			rra(a);
			group[0]--;
		}
		else
			group[1]--;
		pb(a, b);
	}
	move_rest1(a, b, group);
}

static void	two_make_one_b(t_stack *a, t_stack *b, int *group)
{
	while (b -> size > 0 && group[0] > 0 && group[1] > 0)
	{
		if (peek_top(b, 1) < peek_bot(b, 1))
		{
			rrb(b);
			group[0]--;
		}
		else
			group[1]--;
		pa(a, b);
	}
	move_rest2(a, b, group);
}

void	last_sort(t_stack *a, t_stack *b, int *group)
{
	if (b -> size == 0)
		two_make_one_a(a, b, group);
	if (peek_bot(b, 1) <= peek_bot(b, 2))
		while (b -> size > 0)
			pa(a, b);
	else
		two_make_one_b(a, b, group);
}
