NAME	=	push_swap

SRCS	=	push_swap.c \
			algorithm/operations.c \
			algorithm/algorithm.c \
			algorithm/algorithm1.c \
			algorithm/algorithm2.c \
			tools/tools.c \
			tools/tools1.c \
			

FLAGS	=	-Wall -Wextra -Werror -g3 #-fsanitize=address -O0

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

