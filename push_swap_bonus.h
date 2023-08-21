/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:40:13 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/21 14:31:41 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

typedef struct s_list
{
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

typedef struct s_glist
{
	int				fd;
	char			buffer[BUFFER_SIZE + 1];
	struct s_glist	*next;
}t_glist;

int		ft_strlen(char	*command);
int		ft_atoi(char *str);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
void	is_null(char **arr);
void	execute(t_stack *a, t_stack *b, char *command, int len);
void	*all_free(t_glist **head);
void	*free_dest(char *dest);
void	*remove_node(t_glist **head, int fd);
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
t_glist	*find_node(t_glist **head, int fd);

#endif