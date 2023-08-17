/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_one_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:33:36 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 15:34:17 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_three_a(int *op, int box[], int tri_type)
{
	int	arr[3];

	arr[0] = -1;
	arr[1] = -1;
	arr[2] = -1;
	if (op[0] <= op[1] && op[0] <= op[2] && op[1] <= op[2])
		set_arr1(arr, box, 0);
	else if (op[0] <= op[1] && op[0] <= op[2] && op[1] >= op[2])
		set_arr1(arr, box, 1);
	else if (op[0] >= op[1] && op[0] <= op[2] && op[1] <= op[2])
		set_arr1(arr, box, 2);
	else if (op[0] >= op[1] && op[0] >= op[2] && op[1] <= op[2])
		set_arr2(arr, box, 3);
	else if (op[0] <= op[1] && op[0] >= op[2] && op[1] >= op[2])
		set_arr2(arr, box, 4);
	else
		set_arr2(arr, box, 5);
	return (pick_one(arr, tri_type));
}

static int	sort_three_b(int *op, int box[], int tri_type)
{
	int	arr[3];

	arr[0] = -1;
	arr[1] = -1;
	arr[2] = -1;
	if (op[0] <= op[1] && op[0] <= op[2] && op[1] <= op[2])
		set_arr1(arr, box, 0);
	else if (op[0] <= op[1] && op[0] <= op[2] && op[1] >= op[2])
		set_arr1(arr, box, 1);
	else if (op[0] >= op[1] && op[0] <= op[2] && op[1] <= op[2])
		set_arr1(arr, box, 2);
	else if (op[0] >= op[1] && op[0] >= op[2] && op[1] <= op[2])
		set_arr2(arr, box, 3);
	else if (op[0] <= op[1] && op[0] >= op[2] && op[1] >= op[2])
		set_arr2(arr, box, 4);
	else
		set_arr2(arr, box, 5);
	return (pick_one(arr, tri_type));
}

static void	push_to_b(t_stack *a, t_stack *b, int n)
{
	if (n == 0)
		pb(a, b);
	else if (n == 1)
	{
		rra(a);
		pb(a, b);
	}
	else
		rrb(b);
}

static void	push_to_a(t_stack *a, t_stack *b, int n)
{
	if (n == 0)
		pa(a, b);
	else if (n == 1)
	{
		rrb(b);
		pa(a, b);
	}
	else
		rra(a);
}

void	make_one_group(t_stack *a, t_stack *b, int box[], int tri_type)
{
	int	n;
	int	op[3];

	while (!(box[0] == 0 && box[1] == 0 && box[2] == 0))
	{	
		if (box[3] == 0)
		{
			op[0] = peek_top(a, 1);
			op[1] = peek_bot(a, 1);
			op[2] = peek_bot(b, 1);
			n = sort_three_a(op, box, tri_type);
			push_to_b(a, b, n);
			box[n]--;
		}
		else
		{
			op[0] = peek_top(b, 1);
			op[1] = peek_bot(b, 1);
			op[2] = peek_bot(a, 1);
			n = sort_three_b(op, box, tri_type);
			push_to_a(a, b, n);
			box[n]--;
		}
	}
}
