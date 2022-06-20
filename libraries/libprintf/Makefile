P_SRCS		:=	sources/
P_OBJS		:=	.objects/

LST_SRCS	=	ft_printf.c					\
				ft_print_c.c				\
				ft_print_s.c				\
				ft_print_d.c				\
				ft_print_percent.c			\
				ft_print_u.c				\
				ft_print_x_upx.c			\
				ft_print_p.c				\
				ft_putchar_fd.c				\
				ft_putstr_fd.c				\
				ft_putnbr_fd.c				\
				ft_putnbr_base_fd.c			\
				ft_putaddress_fd.c			\
				ft_put_unsigned_nbr_fd.c	\
				ft_strlen.c					
LST_OBJS	:=	${LST_SRCS:.c=.o}
SRCS		:=	$(addprefix ${P_SRCS},${LST_SRCS})
OBJS		:=	$(addprefix ${P_OBJS},${LST_OBJS})
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror
RM			:=	rm -rf
AR			:=	ar rc
RL			:=	ranlib
NAME	= 	libftprintf.a
HEADER	=	ft_printf.h

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

${NAME} : $(OBJS)
	@${AR} ${NAME} ${OBJS}
	@${RL} ${NAME}
	@printf "$(PURPLE)$(BOLD)Library $(NAME) created$(RESET)\n"

${P_OBJS}%.o: ${P_SRCS}%.c $(HEADER)
	@mkdir -p .objects
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