/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:39:38 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/08 16:22:51 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	rra(a);
	rrb(b);
}

t_stack	*make_stack(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (s == NULL)
		exit(1);
	s -> size = 0;
	s -> top = NULL;
	s -> bot = NULL;
	return (s);
}

t_list	*make_lst(char *str)
{
	t_list	*lst;
	int		val;

	val = atoi(str);
	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		exit(1);
	lst -> up = NULL;
	lst -> down = NULL;
	lst -> val = val;
	return (lst);
}