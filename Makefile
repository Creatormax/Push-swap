NAME	=	push_swap

SRCS	=	push_swap.c \
			operations.c \
			

FLAGS	=	-Wall -Wextra -Werror

OBJS	=	$(SRCS:.c=.o)

LIBFT	=	./libft/libft.a

CC		=	gcc

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(INCL) $(LIBFT)
	$(CC) $(FLAGS) $(SRCS) -Iincludes $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C ./libft/
	
clean:
	@rm -rf $(OBJS)
	@echo "cleaning .o files"	
	@make fclean -C ./libft/

fclean: clean
	@rm -rf $(NAME)

re: fclean all

