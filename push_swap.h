/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:40:13 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/16 17:26:16 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

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
 
t_list	*pop_u(t_stack *s);
t_list	*pop_d(t_stack *s);
void	push_u(t_stack *s, t_list *new);
void	push_d(t_stack *s, t_list *new);
t_list	*make_lst(char *str);
t_stack	*make_stack(void);
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
void	free_exit(t_stack *a, t_stack *b);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

#endif