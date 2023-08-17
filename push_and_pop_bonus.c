/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_pop_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:39:38 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 17:14:08 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_u(t_stack *s, t_list *new)
{
	if (s -> size == 0)
		s -> bot = new;
	else
		s -> top -> up = new;
	new -> down = s -> top;
	new -> up = NULL;
	s -> top = new;
	s -> size++;
}	

void	push_d(t_stack *s, t_list *new)
{
	if (s -> size == 0)
		s -> top = new;
	else
		s -> bot -> down = new;
	new -> up = s -> bot;
	new -> down = NULL;
	s -> bot = new;
	s -> size++;
}

t_list	*pop_u(t_stack *s)
{
	t_list	*lst;

	lst = s -> top;
	s -> top = s -> top -> down;
	lst -> down = NULL;
	s -> size--;
	if (s -> size == 0)
		s -> bot = NULL;
	else
		s -> top -> up = NULL;
	return (lst);
}

t_list	*pop_d(t_stack *s)
{
	t_list	*lst;

	lst = s -> bot;
	s -> bot = s -> bot -> up;
	lst -> up = NULL;
	s -> size--;
	if (s -> size == 0)
		s -> top = NULL;
	else
		s -> bot -> down = NULL;
	return (lst);
}
