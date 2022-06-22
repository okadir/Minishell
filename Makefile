CC = gcc
FLAGS = -lreadline -fsanitize=address -static-libsan
NAME = minishell

LIBFT = -L ./libft/  -lft
LEXER = -L ./srcs/lexer/  -llexer
PARSER = -L ./srcs/parser/  -lparser


ENVSRCS = $(addprefix srcs/env/, get_env.c)
LIST_FUNCS = $(addprefix srcs/linked_lists/, tokennew.c tokenadd_front.c \
			tokenadd_back.c tokensize.c tokenlast.c \
			shell_new.c shell_last.c shell_size.c shelladd_back.c \
			shelladd_front.c)

.PHONY: all clean fclean re libft/libft.a \
		srcs/lexer/liblexer.a srcs/lexer/libparser.a

all: $(NAME)

libft/libft.a:
	@make bonus -sC libft/

srcs/lexer/liblexer.a:
	@make -sC srcs/lexer/

srcs/lexer/libparser.a:
	@make -sC srcs/parser/

$(NAME): libft/libft.a srcs/lexer/liblexer.a srcs/lexer/libparser.a minishell.c $(ENVSRCS) $(LIST_FUNCS)
	@$(CC) $(FLAGS) minishell.c $(LIBFT) $(ENVSRCS) $(LIST_FUNCS) \
	$(PARSER) $(LEXER) -o $(NAME) -g
	@echo "\033[1;34mMinishell Compield successfuly\033[0m"

clean:
	@make clean -sC ./libft/
	@make clean -sC ./srcs/lexer/
	@make clean -sC ./srcs/parser/

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC ./libft/
	@make fclean -sC ./srcs/lexer/
	@make fclean -sC ./srcs/parser/

re: fclean all
