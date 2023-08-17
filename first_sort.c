/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:36:54 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 16:32:24 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*generate_group(int g)
{
	int	*group;

	group = malloc(sizeof(int) * g);
	if (group == NULL)
		error();
	return (group);
}

static void	move_to_b(t_stack *a, t_stack *b, int g)
{
	int	i;

	i = 0;
	while (i < g)
	{
		pb(a, b);
		i++;
	}
}

int	*first_sort(t_stack *a, t_stack *b, int *tri, int g)
{
	int	*group;
	int	group_num;
	int	member_num;
	int	i;

	group = generate_group(g);
	move_to_b(a, b, g);
	member_num = (a -> size + b -> size) / g;
	group_num = g - (a -> size + b -> size) % g;
	i = 0;
	if (member_num == 5)
		while (i++ < (g - group_num))
			pb(a, b);
	i = 0;
	while (i < g)
	{
		if (i < group_num)
			group[i] = get_mem_num(a, b, member_num, tri[tri[0]--]);
		else
			group[i] = get_mem_num(a, b, member_num + 1, tri[tri[0]--]);
		i++;
	}
	return (group);
}
