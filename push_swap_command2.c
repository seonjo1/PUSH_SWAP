/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:39:38 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/08 16:19:02 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	t_list	*tmp_a1;
	t_list	*tmp_a2;

	if (a -> size > 1)
	{
		tmp_a1 = pop_u(a);
		tmp_a2 = pop_u(a);
		push_u(a, tmp_a2);
		push_u(a, tmp_a1);
	}
}

void	sb(t_stack *b)
{
	t_list	*tmp_b1;
	t_list	*tmp_b2;

	if (b -> size > 1)
	{
		tmp_b1 = pop_u(b);
		tmp_b2 = pop_u(b);
		push_u(b, tmp_b2);
		push_u(b, tmp_b1);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b -> size > 0)
		push_u(a, pop_u(b));
}

void	pa(t_stack *a, t_stack *b)
{
	if (a -> size > 0)
		push_u(b, pop_u(a));
}
