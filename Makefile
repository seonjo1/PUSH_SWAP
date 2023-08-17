NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = command1.c command2.c command3.c first_sort.c ft_atoi.c ft_split.c get_g_tri.c get_mem_num.c last_sort.c make_and_error.c make_one_group.c make_one_group2.c min_case1.c min_case2.c peek.c push_and_pop.c push_swap.c sort_start.c
SRCS2 = command1_bonus.c command2_bonus.c command3_bonus.c ft_atoi_bonus.c ft_split_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c make_and_error_bonus.c man_bonus.c push_swap_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS2 = $(SRCS:.c=.o)

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus : $(BONUS)

$(BONUS) : $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o $(BONUS)

%.o : %.c
	$(CC) $(CFLAGS) -I . -c $<

clean :
	rm -f $(OBJS)
	rm -f $(OBJS2)

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS)

re : fclean all