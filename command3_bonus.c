/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:39:38 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 20:35:29 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_stack *a)
{
	if (a -> size > 1)
		push_u(a, pop_d(a));
}

void	rrb(t_stack *b)
{
	if (b -> size > 1)
		push_u(b, pop_d(b));
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a -> size > 1)
		push_u(a, pop_d(a));
	if (b -> size > 1)
		push_u(b, pop_d(b));
}
