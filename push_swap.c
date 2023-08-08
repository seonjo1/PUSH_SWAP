/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:40:11 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/08 16:47:58 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = make_stack();
	i = 1;
	while (i <= argc)
		push_d(a, make_lst(argv[i++]));
	get_group_number(a);
}

void	get_group_number(t_stack *a)
{
	int	size;
	int	g;
	int	p;

	p = 1;
	g = 1;
	size = a -> size;
	while (size <= p)
	{
		if (p <= size < p * 2)
			g = p / 3;
		else if (p * 2 <= size < p * 3)
			g = 2 * (p / 3);
		p = p * 3;
	}
	get_triangle_order(a, g);
}

void	get_triangle_order(t_stack *a, int g)
{
	int	*tri;
	int	tri_size;
	int	tmp;

	tmp = g;
	tri_size = g;
	while (tmp > 2)
	{
		tmp = tmp / 3;
		tri_size += tmp;
	}
	if (tmp == 2)
		tri_size++;
	tri = malloc(sizeof(int) * tri_size);
	
}