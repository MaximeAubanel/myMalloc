
LIB_SRC 	= 		my_malloc.c		\
				chain_list.c		\
				fonction.c		\
				free.c			\
				calloc.c		\
				realloc.c		\
				fonction_extend.c

NB_NAME		=		test

LIB_NAME	=		libmy_malloc.so

RM		= 		rm -f

CPPFLAGS 	+= 		-W -Werror -Wextra -Wall

CPPFLAGS 	+= 		-fPIC -D_REENTRANT

CC 		= 		gcc -g -g3

LIB_OBJ		=		$(LIB_SRC:.c=.o)

all: 		$(LIB_NAME)

$(LIB_NAME):	$(LIB_OBJ)
				$(CC) -shared $(LIB_OBJ) -o $(LIB_NAME) -lpthread

clean:
				$(RM) 	$(LIB_OBJ)

fclean: 	clean
				$(RM) 	$(LIB_NAME)

re: 		fclean all

.PHONY: all clean fclean re
