NAME = libft.a
FLAGS = -Wall -Werror -Wextra -g3
RM = rm -rf
SRCS =	libft/ft_isalpha.c\
		libft/ft_isdigit.c\
		libft/ft_isalnum.c\
		libft/ft_isascii.c\
		libft/ft_strlen.c\
		libft/ft_atoi.c\
		libft/ft_bzero.c\
		libft/ft_calloc.c\
		libft/ft_strdup.c\
		libft/ft_putendl_fd.c\
		libft/ft_putstr_fd.c\
		libft/ft_strncmp.c\
		libft/ft_substr.c\
		libft/ft_free_tab.c\
		libft/ft_split.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		printf/ft_printf.c\
		printf/ft_printf_utils.c\
		printf/ft_printf_hexa.c\
		libft/ft_lstnew_bonus.c\
		libft/ft_lstadd_front_bonus.c\
		libft/ft_lstsize_bonus.c\
		libft/ft_lstlast_bonus.c\
		libft/ft_lstadd_back_bonus.c\
		libft/ft_lstclear_bonus.c\

SRCS_BONUS = $(SRCS) \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

.c.o:
	cc $(FLAGS) -c -o $@ $<

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

.PHONY: all clean fclean re
