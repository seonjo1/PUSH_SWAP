/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:21:32 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 14:22:21 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
