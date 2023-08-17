/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:39:38 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 20:35:44 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack *a)
{
	if (a -> size > 1)
		push_d(a, pop_u(a));
}

void	rb(t_stack *b)
{
	if (b -> size > 1)
		push_d(b, pop_u(b));
}

void	rr(t_stack *a, t_stack *b)
{
	if (a -> size > 1)
		push_d(a, pop_u(a));
	if (b -> size > 1)
		push_d(b, pop_u(b));
}
