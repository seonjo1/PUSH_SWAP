NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = command1.c command2.c command3.c first_sort.c ft_atoi.c ft_split.c get_g_tri.c get_mem_num.c last_sort.c make_and_error.c make_one_group.c make_one_group2.c min_case1.c min_case2.c peek.c push_and_pop.c push_swap.c sort_start.c
OBJS = $(SRCS:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I . -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all