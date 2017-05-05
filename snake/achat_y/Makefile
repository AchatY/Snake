##
## Makefile for Makefile in /home/achat/Documents/DEVC/achat_y
## 
## Made by Achat Youmer
## Login   <achat_y_e@etna-alternance.net>
## 
## Started on  Thu May  4 22:18:36 2017 Achat Youmer
## Last update Thu May  4 22:36:14 2017 Achat Youmer
##
CC		=	gcc

NAME		=	snake

SRC		=	affichage.c \
			main.c \
			deplacement_snake.c \
			liste_chainer.c \
			obstacles.c \
			my_putstr.c \
			getnbr.c \
			score.c \
			func_calc.c \
			bonus_rejouer.c \
			my_put_nbr.c \
			my_strcat.c

OBJS		=	$(SRC:.c=.o)
SDL		=	-lSDLmain -lSDL -lSDL_image  -lSDL_ttf

MAKELIB		=	make

CFLAGS		=	-Wall -Werror -Wextra

RM		=	rm -rf

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(CFLAGS) -L $(SDL)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	fclean all re
