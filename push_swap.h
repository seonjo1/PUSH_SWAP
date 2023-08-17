/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:40:13 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 16:10:18 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list{
	int				val;
	struct s_list	*up;
	struct s_list	*down;
}t_list;

typedef struct s_stack
{
	int		size;
	t_list	*top;
	t_list	*bot;
}t_stack;

int		peek_top(t_stack *s, int n);
int		peek_bot(t_stack *s, int n);
int		get_mem_num(t_stack *a, t_stack *b, int member_num, int tri_type);
int		*first_sort(t_stack *a, t_stack *b, int *tri, int g);
int		*sort_start(t_stack *a, t_stack *b, int *tri, int g);
int		*get_tri(int g);
int		get_g(t_stack *a);
int		ft_atoi(char *str);
int		pick_one(int arr[], int tri_type);
void	set_arr1(int arr[], int box[], int type);
void	set_arr2(int arr[], int box[], int type);
char	**ft_split(char const *s, char c);
void	last_sort(t_stack *a, t_stack *b, int *group);
void	make_one_group(t_stack *a, t_stack *b, int box[], int tri_type);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	sort_six(t_stack *a, t_stack *b);
void	sort_seven(t_stack *a, t_stack *b);
void	min_case(t_stack *a, t_stack *b);
void	error(void);
void	push_u(t_stack *s, t_list *new);
void	push_d(t_stack *s, t_list *new);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
t_list	*pop_u(t_stack *s);
t_list	*pop_d(t_stack *s);
t_list	*make_lst(char *str);
t_stack	*make_stack(void);

#endif