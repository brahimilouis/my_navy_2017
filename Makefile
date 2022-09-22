##
## EPITECH PROJECT, 2017
## make
## File description:
## file
##

CC	=	gcc -g

SRCS	=	src/main.c		\
		src/display_map.c	\
		src/get_next_line.c	\
		src/my_putchar.c	\
		src/my_put_nbr.c	\
		src/my_getnbr.c		\
		src/my_putstr.c		\
		src/my_strlen.c		\
		src/connect_player.c	\
		src/connect_game.c	\
		src/check_attack.c	\
		src/game.c		\
		src/play.c		\
		src/recup_pid.c		\
		src/send_pid.c		\
		src/send_signal.c	\
		src/convert_int_str.c	\
		src/wait_other.c	\
		src/check_victory.c	\
		src/display_game.c	\
		src/recup_data.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-I./include

CFLAGS	+=	-W -Wall -pedantic

NAME	=	navy

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)
		rm $(OBJS)

all:		$(NAME)

clean:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
