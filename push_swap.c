/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:40:11 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/15 22:08:18 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *s)
{
	t_list	*now;
	t_list	*tmp;

	now = s -> bot;
	while (now != NULL)
	{
		tmp = now -> up;
		free(now);
		now = tmp;
	}
	free(s);
}

void	free_exit(t_stack *a, t_stack *b)
{
	if (a != NULL)
		free_stack(a);
	if (b != NULL)
		free_stack(b);
	exit(1);
}

int	peek_top(t_stack *s, int n)
{
	t_list	*ptr;
	int		i;

	if (s -> size == 0)
		return (-2147483648);
	i = 1;
	ptr = s -> top;
	while (i++ < n)
		ptr = ptr -> down;
	return (ptr -> val);
}

int	peek_bot(t_stack *s, int n)
{
	t_list	*ptr;
	int		i;

	if (s -> size == 0)
		return (-2147483648);
	i = 1;
	ptr = s -> bot;
	while (i++ < n)
		ptr = ptr -> up;
	return (ptr -> val);
}

void	move_rest1(t_stack *a, t_stack *b, int *group)
{
	if (group[0] > 0)
	{
		while (group[0]-- > 0)
		{
			rra(a);
			pb(a, b);
		}
	}
	if (group[1] > 0)
		while (group[1]-- > 0)
			pb(a, b);
}

void	move_rest2(t_stack *a, t_stack *b, int *group)
{
	if (group[0] > 0)
	{
		while (group[0]-- > 0)
		{
			rrb(b);
			pa(a, b);
		}
	}
	if (group[1] > 0)
		while (group[1]-- > 0)
			pa(a, b);
}

void	two_merge1(t_stack *a, t_stack *b, int *group)
{
	while (a -> size > 0 && group[0] > 0 && group[1] > 0)
	{
		if (peek_top(a, 1) > peek_bot(a, 1))
		{
			rra(a);
			group[0]--;
		}
		else
			group[1]--;
		pb(a, b);
	}
	move_rest1(a, b, group);
}

void	two_merge2(t_stack *a, t_stack *b, int *group)
{
	while (b -> size > 0 && group[0] > 0 && group[1] > 0)
	{
		if (peek_top(b, 1) < peek_bot(b, 1))
		{
			rrb(b);
			group[0]--;
		}
		else
			group[1]--;
		pa(a, b);
	}
	move_rest2(a, b, group);
}

void	last_sort(t_stack *a, t_stack *b, int *group)
{
	if (b -> size == 0)
		two_merge1(a, b, group);
	else if (peek_bot(b, 1) <= peek_bot(b, 2))
		while (b -> size > 0)
			pa(a, b);
	else
		two_merge2(a, b, group);
}

void	move_set(t_stack *a, t_stack *b, int *group, int g)
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

void	set_box2(int box[], int *group, int *tri)
{
	box[0] = group[tri[box[5] + 1]--];
	box[1] = group[tri[box[5] + 2]++];
	box[2] = group[tri[box[5] + 3]--];
}

int	*init_box(t_stack *a, t_stack *b, int *tri, int g)
{
	int	*box;

	box = malloc(sizeof(int) * 6);
	if (box == NULL)
		return (NULL);
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

void	*free_arr(int *arr1, int *arr2, int *arr3, int *arr4)
{
	if (arr1 != NULL)
		free(arr1);
	if (arr2 != NULL)
		free(arr2);
	if (arr3 != NULL)
		free(arr3);
	if (arr4 != NULL)
		free(arr4);
	return (NULL);
}

void	set_arr1(int arr[], int box[], int type)
{
	int	i;

	if (type == 0)
	{
		arr[0] = 0;
		arr[1] = 1;
		arr[2] = 2;
	}
	else if (type == 1)
	{
		arr[0] = 0;
		arr[1] = 2;
		arr[2] = 1;
	}
	else
	{
		arr[0] = 1;
		arr[1] = 0;
		arr[2] = 2;
	}
	i = -1;
	while (++i < 3)
		if (box[arr[i]] == 0)
			arr[i] = -1;
}

void	set_arr2(int arr[], int box[], int type)
{
	int	i;

	if (type == 3)
	{
		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 0;
	}
	else if (type == 4)
	{
		arr[0] = 2;
		arr[1] = 0;
		arr[2] = 1;
	}
	else
	{
		arr[0] = 2;
		arr[1] = 1;
		arr[2] = 0;
	}
	i = -1;
	while (++i < 3)
		if (box[arr[i]] == 0)
			arr[i] = -1;
}

int	pick_one(int arr[], int tri_type)
{
	int	i;

	i = 0;
	if (tri_type == 0)
	{
		i = 2;
		while (i >= 0)
		{
			if (arr[i] != -1)
				break ;
			i--;
		}
	}
	else
	{
		while (i <= 2)
		{
			if (arr[i] != -1)
				break ;
			i++;
		}
	}
	return (arr[i]);
}

int	select_n1(int *op, int box[], int tri_type)
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

int	select_n2(int *op, int box[], int tri_type)
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

void	push_to_b(t_stack *a, t_stack *b, int n)
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

void	push_to_a(t_stack *a, t_stack *b, int n)
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

void	group_make(t_stack *a, t_stack *b, int box[], int tri_type)
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
			n = select_n1(op, box, tri_type);
			push_to_b(a, b, n);
			box[n]--;
		}
		else
		{
			op[0] = peek_top(b, 1);
			op[1] = peek_bot(b, 1);
			op[2] = peek_bot(a, 1);
			n = select_n2(op, box, tri_type);
			push_to_a(a, b, n);
			box[n]--;
		}
	}
}

void	set_box(int *box, int member_num)
{
	box[0] = box[0] + (member_num - 3);
	if (member_num == 6)
	{
		box[0]--;
		box[2]++;
	}
}

void	ascending_sort(t_stack *a, t_stack *b, int member_num)
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

void	descending_sort(t_stack *a, t_stack *b, int member_num)
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

int	merge(t_stack *a, t_stack *b, int member_num, int tri_type)
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
	group_make(a, b, box, tri_type);
	return (member_num);
}

int	*new_group(t_stack *a, t_stack *b, int *tri, int g)
{
	int	*group;
	int	i;

	group = malloc(sizeof(int) * g);
	if (group == NULL)
	{
		free(tri);
		free_exit(a, b);
	}
	i = 0;
	while (i < g)
	{
		pb(a, b);
		i++;
	}
	return (group);
}

int	*first_sort(t_stack *a, t_stack *b, int *tri, int g)
{
	int	*group;
	int	group_num;
	int	member_num;
	int	i;

	group = new_group(a, b, tri, g);
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
			group[i] = merge(a, b, member_num, tri[tri[0]--]);
		else
			group[i] = merge(a, b, member_num + 1, tri[tri[0]--]);
		i++;
	}
	return (group);
}

int	*m_sort(t_stack *a, t_stack *b, int *tri, int g)
{
	int		*group;
	int		*group2;
	int		*box;

	group = first_sort(a, b, tri, g);
		// 	//확인 자리
		// t_list *tmp;
		// printf("\n\na\n");
		// tmp = a -> top;
		// // printf("top : %p\n\n", a -> top);
		// while (tmp != NULL)
		// {
		// 	// printf("up : %p\n", tmp -> up);
		// 	printf("me : %p    val : %d\n", tmp, tmp -> val);
		// 	// printf("down : %p\n\n", tmp -> down);
		// 	tmp = tmp -> down;
		// }
		// // printf("bot : %p\n\n", a -> bot);
		// printf("\nb\n");
		// tmp = b -> top;
		// // printf("top : %p\n\n", b -> top);
		// while (tmp != NULL)
		// {
		// 	// printf("up : %p\n", tmp -> up);
		// 	printf("me : %p    val : %d\n", tmp, tmp -> val);
		// 	// printf("down : %p\n\n", tmp -> down);
		// 	tmp = tmp -> down;
		// }
		// // printf("bot : %p\n\n", b -> bot);
	while (g > 2)
	{
		g = g / 3;
		group2 = malloc(sizeof(int) * g + 1);
		box = init_box(a, b, tri, g);
		if (group2 == NULL || box == NULL)
			return (free_arr(group, group2, box, tri));
		move_set(a, b, group, g);
		while (box[4] < g)
		{	
			set_box2(box, group, tri);
			group2[box[4]++] = box[0] + box[1] + box[2];
			group_make(a, b, box, tri[tri[0]--]);
		}
		free(group);
		group = group2;
	}
	free(tri);
	return (group);
}

static int	last_tri(int g)
{
	int flag;

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

static void	make_tri(int *tri, int g, int i, int j)
{
	int	n;
	int	k;
	int	ptr[4];

	n = 1;
	if (g % 2 == 0)
	{
		tri[j++] = !tri[i];
		tri[j++] = tri[i++];
		n++;
	}
	while (n < g)
	{
		ptr[0] = j;
		ptr[1] = j + n;
		ptr[2] = j + 3 * n - 1;
		ptr[3] = j + 3 * n;
		k = i + n - 1;
		while (j < ptr[3])
		{
			tri[ptr[0]++] = !tri[k];
			tri[ptr[1]++] = !tri[k];
			tri[ptr[2]--] = tri[k--];
			j = j + 3;
		}
		i = i + n;
		n = n * 3;
	}
}

static int	*get_triangle_order(t_stack *a, int g)
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
		free_exit(a, NULL);
	tri[1] = last_tri(g);
	tri[0] = tri_size;
	make_tri(tri, g, 1, 2);
	return (tri);
}

static int	get_group_number(t_stack *a)
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

void	free_exit2(t_stack *s, char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	free_stack(s);
	exit(1);
}

int all_push_a(int argc, char **argv, t_stack *a)
{
	t_list	*lst;
	char	**arr;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		arr = ft_split(argv[i], ' ');
		if (arr == NULL)
			return (0);
		j = 0;
		while (arr[j] != NULL)
		{
			lst = make_lst(arr[j]);
			if (lst == NULL)
				free_exit2(a, arr);
			push_d(a, lst);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*tri;
	int		g;

	a = make_stack();
	b = make_stack();
	if (all_push_a(argc, argv, a) == 0)
		exit(1);
	g = get_group_number(a);
	tri = get_triangle_order(a, g);
	tri = m_sort(a, b, tri, g);
	if (tri == NULL)
		free_exit(a, b);
	while (a -> size < 2 || peek_bot(a, 1) < peek_bot(a, 2))
		last_sort(a, b, tri);
	// //
	// t_list *tmp;
	// tmp = a -> top;
	// while (tmp != NULL)
	// {
	// 	printf("%d\n", tmp -> val);
	// 	tmp = tmp -> down;
	// }
	// tmp = b -> top;
	// while (tmp != NULL)
	// {
	// 	printf("%d\n", tmp -> val);
	// 	tmp = tmp -> down;
	// }
	// //
	free(tri);
}
