P_SRCS		:=	sources/
P_OBJS		:=	.objects/

LST_SRCS	:=	ft_isalpha.c			\
				ft_memcpy.c 			\
				ft_strlcat.c			\
				ft_strtrim.c			\
         		ft_isascii.c			\
				ft_memmove.c			\
				ft_strlcpy.c			\
				ft_substr.c				\
          		ft_atoi.c				\
				ft_isdigit.c			\
				ft_memset.c 			\
				ft_strlen.c				\
				ft_tolower.c			\
				ft_bzero.c				\
				ft_isprint.c			\
				ft_strchr.c				\
				ft_strncmp.c			\
				ft_toupper.c			\
				ft_calloc.c				\
				ft_memchr.c				\
				ft_strdup.c				\
				ft_strnstr.c			\
				ft_isalnum.c			\
				ft_memcmp.c				\
				ft_strjoin.c			\
				ft_strrchr.c			\
				ft_split.c				\
				ft_itoa.c				\
				ft_strmapi.c			\
				ft_striteri.c			\
				ft_putchar_fd.c			\
				ft_putstr_fd.c			\
				ft_putendl_fd.c			\
				ft_putnbr_fd.c			\
				get_next_line.c			\
				get_next_line_utils.c
LST_BONUS	:= 	ft_lstnew.c				\
				ft_lstadd_front.c		\
				ft_lstsize.c			\
				ft_lstlast.c			\
				ft_lstadd_back.c		\
				ft_lstdelone.c			\
				ft_lstclear.c			\
				ft_lstiter.c			\
				ft_lstmap.c
LST_OBJS	:=	${LST_SRCS:.c=.o}
LST_BOBJS	:=	${LST_BONUS:.c=.o}
SRCS		:=	$(addprefix ${P_SRCS},${LST_SRCS})
BONUS		:=	$(addprefix ${P_SRCS},${LST_BONUS})
OBJS		:=	$(addprefix ${P_OBJS},${LST_OBJS})
BOBJS		:=	$(addprefix ${P_OBJS},${LST_BOBJS})
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror
RM			:=	rm -rf
AR			:=	ar rc
RL			:=	ranlib
NAME		:= 	libft.a
HEADER		:=	libft.h

#///////////////////////////////////////////////////////////////////////////////

# Colors
BLACK=\033[30m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
PURPLE=\033[35m
CYAN=\033[36m
WHITE=\033[37m

# Text
ERASE=\033[2K\r
RESET=\033[0m
BOLD=\033[1m
FAINT=\033[2m
ITALIC=\033[3m
UNDERLINE=\033[4m

#///////////////////////////////////////////////////////////////////////////////

all: ${NAME}

${NAME} : $(OBJS) ${BOBJS}
	@${AR} ${NAME} ${OBJS} ${BOBJS}
	@${RL} ${NAME}
	@printf "$(PURPLE)$(BOLD)Library $(NAME) created$(RESET)\n"

${P_OBJS}%.o: ${P_SRCS}%.c $(HEADER)
	@mkdir -p ${P_OBJS}
	@${CC} ${CFLAGS} -I . -c $< -o $@

clean :
	@$(RM) $(OBJS)
	@${RM} ${P_OBJS}
	@printf "$(YELLOW)$(BOLD)All libft object files removed$(RESET)\n"
	@printf "$(YELLOW)$(BOLD)libft object folder removed$(RESET)\n"

fclean :	
	@${MAKE} clean
	@${RM} ${NAME}
	@printf "$(RED)$(BOLD)Library $(NAME) removed $(RESET)\n"

re :		
	@${MAKE} fclean
	@${MAKE} all