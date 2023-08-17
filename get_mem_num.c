/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mem_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:37:19 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 15:50:06 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ascending_sort(t_stack *a, t_stack *b, int member_num)
{
	if (member_num > 3 && peek_top(a, 1) > peek_top(a, 2))
		sa(a);
	if (member_num > 4 && peek_top(a, 2) > peek_top(a, 3))
	{
		ra(a);
		sa(a);
		rra(a);
		if (peek_top(a, 1) > peek_top(a, 2))
			sa(a);
	}
	if (member_num == 6 && peek_bot(b, 1) > peek_bot(b, 2))
	{
		rrb(b);
		rrb(b);
		sb(b);
		rb(b);
		rb(b);
	}
}

static void	descending_sort(t_stack *a, t_stack *b, int member_num)
{
	if (member_num > 3 && peek_top(a, 1) < peek_top(a, 2))
		sa(a);
	if (member_num > 4 && peek_top(a, 2) < peek_top(a, 3))
	{
		ra(a);
		sa(a);
		rra(a);
		if (peek_top(a, 1) < peek_top(a, 2))
			sa(a);
	}
	if (member_num == 6 && peek_bot(b, 1) < peek_bot(b, 2))
	{
		rrb(b);
		rrb(b);
		sb(b);
		rb(b);
		rb(b);
	}
}

static void	set_box(int *box, int member_num)
{
	box[0] = box[0] + (member_num - 3);
	if (member_num == 6)
	{
		box[0]--;
		box[2]++;
	}
}

int	get_mem_num(t_stack *a, t_stack *b, int member_num, int tri_type)
{
	int	box[4];

	if (tri_type == 0)
		descending_sort(a, b, member_num);
	else
		ascending_sort(a, b, member_num);
	box[0] = 1;
	box[1] = 1;
	box[2] = 1;
	box[3] = 0;
	set_box(box, member_num);
	make_one_group(a, b, box, tri_type);
	return (member_num);
}
