NAME		= libft.a

SRCDIR 		= ./src/
SRCNAMES 	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC 		= $(addprefix $(SRCDIR), $(SRCNAMES))
INC 		= ./inc/

BUILDDIR 	= ./build/
BUILDOBJS 	= $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

CC			= gcc
AR			= ar rc
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
# HEADER		= -I libft.h

# .c.o:	${CC} ${FLAGS} -c ${HEADER} $< -o ${<:.c=.o}

all:	${BUILDDIR} ${NAME} 

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)%.o:$(SRCDIR)%.c
	$(CC) $(FLAGS) -I$(INC) -o $@ -c $<

${NAME}:	${BUILDOBJS}
		${AR} ${NAME} ${BUILDOBJS}

clean:	
		${RM} ${BUILDDIR}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.phony: all, clean, fclean, re, bonus