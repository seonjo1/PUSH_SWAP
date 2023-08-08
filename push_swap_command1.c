/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:39:38 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/08 16:18:06 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*pop_u(t_stack *s)
{
	t_list	*lst;

	lst = s -> top;
	s -> top = s -> top -> down;
	s -> top -> up = NULL;
	s -> size--;
	return (lst);
}

t_list	*pop_d(t_stack *s)
{
	t_list	*lst;

	lst = s -> bot;
	s -> bot = s -> bot -> up;
	s -> bot -> down = NULL;
	s -> size--;
	return (lst);
}

void	push_u(t_stack *s, t_list *new)
{
	new -> down = s -> top;
	new -> up = NULL;
	s -> top = new;
	s -> size++;
}

void	push_d(t_stack *s, t_list *new)
{
	new -> up = s -> bot;
	new -> down = NULL;
	s -> bot = new;
	s -> size++;
}	
