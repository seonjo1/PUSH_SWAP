/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:39:38 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/16 17:26:08 by seonjo           ###   ########.fr       */
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

	val = ft_atoi(str);
	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst -> up = NULL;
	lst -> down = NULL;
	lst -> val = val;
	return (lst);
}
