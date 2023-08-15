/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:39:38 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/15 13:51:33 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (a -> size > 1)
	{
		tmp1 = a -> top;
		tmp2 = tmp1 -> down;
		a -> top = tmp2;
		if (a -> size == 2)
			a -> bot = tmp1;
		else
			tmp2 -> down -> up = tmp1;
		tmp1 -> up = tmp2;
		tmp1 -> down = tmp2 -> down;
		tmp2 -> up = NULL;
		tmp2 -> down = tmp1;
		printf("sa\n");
	}
}

void	sb(t_stack *b)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (b -> size > 1)
	{
		tmp1 = b -> top;
		tmp2 = tmp1 -> down;
		b -> top = tmp2;
		if (b -> size == 2)
			b -> bot = tmp1;	
		else
			tmp2 -> down -> up = tmp1;
		tmp1 -> up = tmp2;
		tmp1 -> down = tmp2 -> down;
		tmp2 -> up = NULL;
		tmp2 -> down = tmp1;
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
