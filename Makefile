SRCS		=	main.c  \
				utils.c \
				fractals.c\
				comp.c\
				rendering.c\
				hooks.c\
				colors.c\

NAME		=	fract_ol

OBJ			=	$(SRCS:.c=.o)

DEP			= 	$(SRCS:%.c=%.d)

all			:	$(NAME)

$(CC)		:	gcc

$(NAME)		:	$(OBJ)
				$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o $(NAME)

$(OBJ)		:
				$(CC) -Wall -Wextra -Werror -MP -MMD -c $(SRCS)

clean		:
				rm -f $(OBJ)
				rm -f $(DEP)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all

-include $(DEP)

.PHONY		:	all clean fclean re
