/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:40:11 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 16:41:51 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	all_push(int argc, char **argv, t_stack *a)
{
	t_list	*lst;
	char	**arr;
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		arr = ft_split(argv[i], ' ');
		if (arr == NULL)
			error();
		j = -1;
		while (arr[++j] != NULL)
		{
			lst = make_lst(arr[j]);
			if (lst == NULL)
				error();
			free(arr[j]);
			push_d(a, lst);
		}
		free(arr);
	}
}

static int	is_dup(int *arr, int val, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (arr[j] == val)
			return (1);
		j++;
	}
	arr[i] = val;
	return (0);
}

static void	sort_check(t_stack *a, int flag)
{
	t_list	*now;
	t_list	*next;
	int		*arr;
	int		i;

	if (a -> size == 0)
		exit(0);
	arr = malloc(sizeof(int) * (a -> size));
	i = 0;
	now = a -> top;
	next = now -> down;
	arr[i++] = now -> val;
	while (next != NULL)
	{
		if (now -> val > next -> val)
			flag = 1;
		if (is_dup(arr, next -> val, i++))
			error();
		now = next;
		next = now -> down;
	}
	free(arr);
	if (flag == 0)
		exit(0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*tri;
	int		g;

	a = make_stack();
	b = make_stack();
	all_push(argc, argv, a);
	sort_check(a, 0);
	min_case(a, b);
	g = get_g(a);
	tri = get_tri(g);
	tri = sort_start(a, b, tri, g);
	if (a -> size < 2 || peek_bot(a, 1) < peek_bot(a, 2))
		last_sort(a, b, tri);
	exit(0);
}
