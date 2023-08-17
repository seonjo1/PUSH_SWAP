/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_g_tri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:43:45 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 16:31:03 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_last_tri(int g)
{
	int	flag;

	flag = 1;
	while ((g / 3) > 0)
	{
		g = g / 3;
		flag = !flag;
	}
	if ((flag == 0 && g == 1) || (flag == 1 && g == 2))
		return (0);
	else
		return (1);
}

static void	fill_tri(int *tri, int g, int i, int j)
{
	int	tri_size;
	int	ptr[4];

	tri_size = 1;
	if (i == 1)
		tri_size = 2;
	while (tri_size < g)
	{
		ptr[0] = j;
		ptr[1] = j + tri_size;
		ptr[2] = j + 3 * tri_size - 1;
		ptr[3] = j + 3 * tri_size;
		i = i + tri_size;
		while (j < ptr[3])
		{
			tri[ptr[0]++] = !tri[i];
			tri[ptr[1]++] = !tri[i];
			tri[ptr[2]--] = tri[i--];
			j = j + 3;
		}
		i = i + tri_size;
		tri_size = tri_size * 3;
	}
}

static void	fill_tri_even(int *tri, int g, int i, int j)
{
	if (g % 2 == 0)
	{
		tri[j++] = !tri[++i];
		tri[j++] = tri[i];
	}
	fill_tri(tri, g, i, j);
}

int	*get_tri(int g)
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
	tri = malloc(sizeof(int) * (tri_size + 1));
	if (tri == NULL)
		error();
	tri[0] = tri_size;
	tri[1] = get_last_tri(g);
	if (g % 2 == 0)
		fill_tri_even(tri, g, 0, 2);
	else
		fill_tri(tri, g, 0, 2);
	return (tri);
}

int	get_g(t_stack *a)
{
	int	size;
	int	g;
	int	p;

	p = 1;
	g = 1;
	size = a -> size;
	while (size >= p)
		p = p * 3;
	p = p / 3;
	if (p <= size && size < p * 2)
		g = p / 3;
	else if (p * 2 <= size && size < p * 3)
		g = 2 * (p / 3);
	return (g);
}
