/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:39:38 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/14 21:10:04 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	t_list	*tmp;

	if (a -> size > 1)
	{
		tmp = a -> top -> down;
		tmp -> down -> up = a -> top;
		a -> top -> down = tmp -> down;
		tmp -> down = a -> top;
		a -> top -> up = tmp;
		tmp -> up = NULL;
		a -> top = tmp;
		printf("sa\n");
	}
}

void	sb(t_stack *b)
{
	t_list	*tmp;

	if (b -> size > 1)
	{
		tmp = b -> top -> down;
		tmp -> down -> up = b -> top;
		b -> top -> down = tmp -> down;
		tmp -> down = b -> top;
		b -> top -> up = tmp;
		tmp -> up = NULL;
		b -> top = tmp;
		printf("sb\n");
	}
}

void	ss(t_stack *a, t_stack *b)
{
	t_list	*tmp_a1;
	t_list	*tmp_a2;
	t_list	*tmp_b1;
	t_list	*tmp_b2;

	if (a -> size > 1)
	{
		tmp_a1 = pop_u(a);
		tmp_a2 = pop_u(a);
		push_u(a, tmp_a2);
		push_u(a, tmp_a1);
	}
	if (b -> size > 1)
	{
		tmp_b1 = pop_u(b);
		tmp_b2 = pop_u(b);
		push_u(b, tmp_b2);
		push_u(b, tmp_b1);
	}
	if (a -> size > 1 || b -> size > 1)
		printf("ss\n");
}

void	pa(t_stack *a, t_stack *b)
{
	if (b -> size > 0)
	{
		push_u(a, pop_u(b));
		printf("pa\n");
	}
}

void	pb(t_stack *a, t_stack *b)
{
	if (a -> size > 0)
	{
		push_u(b, pop_u(a));
		printf("pb\n");
	}
}
