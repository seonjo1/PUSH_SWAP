/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:24:26 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 14:24:46 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	peek_top(t_stack *s, int n)
{
	t_list	*ptr;
	int		i;

	if (s -> size == 0)
		return (-2147483648);
	i = 1;
	ptr = s -> top;
	while (i++ < n)
		ptr = ptr -> down;
	return (ptr -> val);
}

int	peek_bot(t_stack *s, int n)
{
	t_list	*ptr;
	int		i;

	if (s -> size == 0)
		return (-2147483648);
	i = 1;
	ptr = s -> bot;
	while (i++ < n)
		ptr = ptr -> up;
	return (ptr -> val);
}
