NAME = so_long

SRCS = controls.c controls2.c create_map.c free.c get_map.c get_next_line.c utils.c utils2.c so_long.c move.c move1.c

OBJS = $(SRCS:.c=.o)

CC = gcc

MFLAGS = ./minilibx/libmlx.a

AFLAGS =  -Wall -Wextra -Werror 

RM = rm -rf

all :$(MFLAGS) $(NAME)

$(MFLAGS):
	make -C ./minilibx

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MFLAGS) $(AFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

fclean : clean
	rm -rf $(NAME)

clean :
	make clean -C ./minilibx
	rm -rf $(OBJS)

re : fclean all

.PHONY : all fclean clean re