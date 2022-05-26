SRCS	=		main.c  \
				utils.c \
				fractals.c\
				comp.c\
				rendering.c\
				hooks.c\

BONUS_SRCS	=	main_bonus.c  \
				utils_bonus.c \
				fractals_bonus.c\
				comp_bonus.c\
				rendering_bonus.c\
				hooks_bonus.c\
				colors_bonus.c\

BONUS_NAME	=	fract_ol_bonus

NAME		=	fract_ol

BONUS_OBJ	=	$(BONUS_SRCS:.c=.o)

OBJ			=	$(SRCS:.c=.o)

BONUS_DEP	= 	$(BONUS_SRCS:%.c=%.d)

DEP	= 			$(SRCS:%.c=%.d)

all			:	$(NAME)

$(CC)		:	gcc

$(BONUS_NAME)	:	$(BONUS_OBJ)
				make -C "mlx_linux/"
				$(CC) $(BONUS_OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o $(BONUS_NAME)

$(NAME)			:	$(OBJ)
				make -C "mlx_linux/"
				$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o $(NAME)

$(BONUS_OBJ)		:
				$(CC) -Wall -Wextra -Werror -MP -MMD -c $(BONUS_SRCS)

$(OBJ)		:
				$(CC) -Wall -Wextra -Werror -MP -MMD -c $(SRCS)

clean		:
				rm -f $(BONUS_OBJ)
				rm -f $(BONUS_DEP)
				rm -f $(OBJ)
				rm -f $(DEP)

fclean		:	clean
				rm -f $(BONUS_NAME)
				rm -f $(NAME)

re			:	fclean all

bonus		:	$(BONUS_NAME)

-include $(BONUS_DEP)

.PHONY		:	all clean fclean re bonus
