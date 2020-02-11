C = clang

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

DIR_O = obj

DIR_S = srcs

DIR_H = includes

LIBFT = libft

FILES = flags.c \
ft_printf.c \
ft_printf.h \
new.c \

FILES_MAIN = srcs/flags.c \
srcs/ft_printf.c \
srcs/ft_printf.h \
srcs/new.c \

SRCS = $(addprefix $(DIR_S)/,$(FILES))

OBJS = $(addprefix $(DIR_O)/,$(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(DIR_H)/libftprintf.h
	@mkdir -p $(DIR_O)
	@$(CC) -I $(DIR_H) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

main: fclean all
	@gcc $(FILES_MAIN) $(LIBFT)/libft.a
	@./a.out

test:
	@rm -rf test
	@gcc test.c libft/libft.a
	@./a.out

.PHONY: all clean fclean re