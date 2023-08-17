/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_case2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:40:10 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 14:41:48 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stack *a)
{
	int		i;
	int		min;
	int		idx;
	t_list	*tmp;

	i = 1;
	min = 2147483647;
	tmp = a -> top;
	while (tmp != NULL)
	{
		if (min >= tmp -> val)
		{
			min = tmp -> val;
			idx = i;
		}
		i++;
		tmp = tmp -> down;
	}
	return (idx);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int		idx;

	idx = find_min(a);
	if (idx == 2)
		sa(a);
	else if (idx != 1)
	{
		rra(a);
		if (idx == 3)
			rra(a);
	}	
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	an;
	int	bn;

	sort_two(a);
	pb(a, b);
	pb(a, b);
	sort_three(a);
	an = 3;
	bn = 2;
	while (an > 0 || bn > 0)
	{
		if (an == 0 || peek_bot(a, 1) < peek_top(b, 1))
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

void	sort_six(t_stack *a, t_stack *b)
{
	int	an;
	int	bn;

	sort_three(a);
	pb(a, b);
	pb(a, b);
	pb(a, b);
	sort_three(a);
	an = 3;
	bn = 3;
	while (an > 0 || bn > 0)
	{
		if (an == 0 || peek_bot(a, 1) < peek_top(b, 1))
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

void	sort_seven(t_stack *a, t_stack *b)
{
	int	an;
	int	bn;

	sort_three(a);
	pb(a, b);
	pb(a, b);
	pb(a, b);
	sort_four(a, b);
	an = 3;
	bn = 4;
	while (an > 0 || bn > 0)
	{
		if (an == 0 || peek_bot(a, 1) < peek_top(b, 1))
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
