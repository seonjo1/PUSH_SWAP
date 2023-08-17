/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:39:38 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 14:21:50 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	if (a -> size > 1)
	{
		push_u(a, pop_d(a));
		if (write(1, "rra\n", 4) == -1)
			exit(1);
	}
}

void	rrb(t_stack *b)
{
	if (b -> size > 1)
	{	
		push_u(b, pop_d(b));
		if (write(1, "rrb\n", 4) == -1)
			exit(1);
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a -> size > 1)
		push_u(a, pop_d(a));
	if (b -> size > 1)
		push_u(b, pop_d(b));
	if (a -> size > 1 || b -> size > 1)
		if (write(1, "rrr\n", 4) == -1)
			exit(1);
}
