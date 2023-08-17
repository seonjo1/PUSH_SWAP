/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:40:11 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 21:45:49 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		is_null(arr);
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

static void	is_dup(t_stack *a, int i, int j)
{
	t_list	*now;
	t_list	*next;
	int		*arr;

	arr = malloc(sizeof(int) * (a -> size));
	now = a -> top;
	next = now -> down;
	arr[i++] = now -> val;
	while (next != NULL)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] == next -> val)
				error();
			j++;
		}
		now = next;
		next = now -> down;
	}
	free(arr);
}

static int	sort_check(t_stack *a, int flag)
{
	t_list	*now;
	t_list	*next;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * (a -> size));
	i = 0;
	now = a -> top;
	next = now -> down;
	arr[i++] = now -> val;
	while (next != NULL)
	{
		if (now -> val > next -> val)
			flag = 1;
		now = next;
		next = now -> down;
	}
	free(arr);
	return (flag);
}

static void	write_sign(char *sign)
{
	if (write(1, sign, 3) < 0)
		error();
}

int	main(int argc, char **argv)
{
	char	*man;
	t_stack	*a;
	t_stack	*b;

	a = make_stack();
	b = make_stack();
	all_push(argc, argv, a);
	is_dup(a, 0, 0);
	man = get_next_line(0);
	while (man != NULL)
	{
		execute(a, b, man);
		man = get_next_line(0);
	}
	if (sort_check(a, 0) == 0 && b -> size == 0)
		write_sign("OK\n");
	else
		write_sign("KO\n");
	exit(0);
}
