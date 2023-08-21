/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:41:08 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/21 18:18:04 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_third(t_stack *a, t_stack *b, int *group, int g)
{
	int	i;
	int	j;

	i = g * 3 - 1;
	if (a -> size > b -> size)
	{
		while (i >= g * 2)
		{
			j = 0;
			while (j++ < group[i])
				pb(a, b);
			i--;
		}
	}
	else
	{
		while (i >= g * 2)
		{
			j = 0;
			while (j++ < group[i])
				pa(a, b);
			i--;
		}
	}
}

static void	move_ptr(int box[], int *group, int *tri)
{
	box[0] = group[tri[box[5] + 1]--];
	box[1] = group[tri[box[5] + 2]++];
	box[2] = group[tri[box[5] + 3]--];
}

static int	*init_box(t_stack *a, t_stack *b, int *tri, int g)
{
	int	*box;

	box = malloc(sizeof(int) * 6);
	if (box == NULL)
		error();
	box[0] = 0;
	box[1] = 0;
	box[2] = 0;
	box[3] = 0;
	if (a -> size < b -> size)
		box[3] = 1;
	box[4] = 0;
	box[5] = tri[0];
	tri[box[5] + 1] = g * 2 - 1;
	tri[box[5] + 2] = 0;
	tri[box[5] + 3] = g * 3 - 1;
	return (box);
}

void	free_arr(int *arr1, int *arr2)
{
	if (arr1 != NULL)
		free(arr1);
	if (arr2 != NULL)
		free(arr2);
}

int	*sort_start(t_stack *a, t_stack *b, int *tri, int g)
{
	int		*box;
	int		*group;
	int		*next_group;

	group = first_sort(a, b, tri, g);
	while (g > 2)
	{
		g = g / 3;
		next_group = malloc(sizeof(int) * g + 1);
		if (next_group == NULL)
			error();
		box = init_box(a, b, tri, g);
		move_third(a, b, group, g);
		while (box[4] < g)
		{	
			move_ptr(box, group, tri);
			next_group[box[4]++] = box[0] + box[1] + box[2];
			make_one_group(a, b, box, tri[tri[0]--]);
		}
		free(group);
		group = next_group;
	}
	free_arr(tri, box);
	return (group);
}
