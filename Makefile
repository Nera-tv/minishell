.PHONY :	re fclean clean all
.SILENT:

LST_SRCS	=	builtins.c			\
				cd.c				\
				echo.c				\
				env.c				\
				exit.c				\
				export.c			\
				main.c				\
				p_args.c			\
				p_cmd_utils.c		\
				p_cmd.c				\
				p_free_cmd.c		\
				p_option.c			\
				pwd.c				\
				readline.c			\
				unset.c			


P_LIB		:=	libraries/
P_LFT		:=	$(P_LIB)libft/
P_LPF		:=	$(P_LIB)libprintf/
P_INC		:=	includes/
P_SRCS		:=	sources/
P_OBJS		:=	.objects/

LST_OBJS	:=	${LST_SRCS:.c=.o}
SRCS		:=	$(addprefix ${P_SRCS},${LST_SRCS})
OBJS		:=	$(addprefix ${P_OBJS},${LST_OBJS})


CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -fsanitize=address -g3
RLOFLAGS	:=	-lreadline
NAME		:= 	minishell
HEADER		:=	${P_INC}minishell.h				\
				${P_INC}struct.h				\
				${P_INC}error_msg.h				\
				${P_LFT}libft.h					\
				${P_LPF}ft_printf.h

RM			:=	rm -rf
LFTA		:=	${P_LFT}libft.a
LPFA		:=	${P_LPF}libftprintf.a
USAGE		=	$(BLUE)$(BOLD)Usage : ./${NAME} $(RESET)\n

#///////////////////////////////////////////////////////////////////////////////

# Colors
BLACK		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PURPLE		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m

# Text
ERASE		=	\033[2K\r
RESET		=	\033[0m
BOLD		=	\033[1m
FAINT		=	\033[2m
ITALIC		=	\033[3m
UNDERLINE	=	\033[4m

BBLU 		=	\033[1;34m
BGREEN		=	\033[1;32m
BRED		=	\033[1;31m
BLU 		=	\033[0;34m
MGT			=	\033[0;35m
LMGT		=	\033[0;95m
LBLU 		=	\033[0;96m
GRN 		=	\033[0;32m
RED 		=	\033[0;31m
GRY 		=	\033[0;90m
RST 		=	\033[0m
#///////////////////////////////////////////////////////////////////////////////

all: print_header makelft makelpf ${NAME} usage print_bottom

${NAME} : ${P_OBJS} ${OBJS} ${HEADER} ${LFTA} ${LPFA}
	@${CC} ${CFLAGS} ${OBJS} -o $(NAME) ${RLOFLAGS} ${LFTA} ${LPFA}
	@printf "\n$(GREEN)$(BOLD)Binary $(NAME) created$(RESET)	✅\n"

$(P_OBJS)%.o: $(P_SRCS)%.c $(HEADER) $(LFTA) $(LPFA) Makefile | $(P_OBJS)
	@${CC} ${CFLAGS} -c $< -o $@
	@printf "$(FAINT)$(CC) $(CFLAGS) $(RLOFLAGS) -c -o $(RESET)$(CYAN)$(BOLD)$@$(RESET) $(FAINT)$(BLUE)$<$(RESET)\n"

$(P_OBJS):
	@mkdir -p $(P_OBJS)
	@printf "$(GREEN)$(BOLD)${NAME} objects directories created$(RESET)	✅\n\n"

print_header:
	@echo "${GRY}====================================================================${RST}\n"
	@echo " ▄▄   ▄▄ ▄▄▄ ▄▄    ▄ ▄▄▄ ▄▄▄▄▄▄▄ ▄▄   ▄▄ ▄▄▄▄▄▄▄ ▄▄▄     ▄▄▄     "
	@echo "█  █▄█  █   █  █  █ █   █       █  █ █  █       █   █   █   █    "
	@echo "█       █   █   █▄█ █   █  ▄▄▄▄▄█  █▄█  █    ▄▄▄█   █   █   █    "
	@echo "█       █   █       █   █ █▄▄▄▄▄█       █   █▄▄▄█   █   █   █    "
	@echo "█       █   █  ▄    █   █▄▄▄▄▄  █   ▄   █    ▄▄▄█   █▄▄▄█   █▄▄▄ "
	@echo "█ ██▄██ █   █ █ █   █   █▄▄▄▄▄█ █  █ █  █   █▄▄▄█       █       █"
	@echo "█▄█   █▄█▄▄▄█▄█  █▄▄█▄▄▄█▄▄▄▄▄▄▄█▄▄█ █▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█"
	@echo "\n${GRY}====================================================================${RST}\n"

usage:
	@printf "$(USAGE)"

print_bottom:
	@echo "\n${GRY}=================================================${RST}\n"
	@echo " ▄   ▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄     ▄▄   ▄▄ ▄▄▄▄▄▄▄ ▄▄    ▄ "
	@echo "█ █ █   █       █   █   █  █ █  █       █  █  █ █"
	@echo "█ █▄█   █▄▄▄▄   █   █   █  █▄█  █   ▄   █   █▄█ █"
	@echo "█       █▄▄▄▄█  █   █   █       █  █ █  █       █"
	@echo "█▄▄▄    █ ▄▄▄▄▄▄█   █▄▄▄█▄     ▄█  █▄█  █  ▄    █"
	@echo "    █   █ █▄▄▄▄▄█       █ █   █ █       █ █ █   █"
	@echo "    █▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█ █▄▄▄█ █▄▄▄▄▄▄▄█▄█  █▄▄█"
	@echo "\n${GRY}==================>${RST} By ${LMGT}dvilard${RST} ${GRY}<=================${RST}\n"

$(LFTA): makelft

makelft:
	@${MAKE} -C $(P_LIB)libft

$(LPFA): makelpf

makelpf:
	@${MAKE} -C $(P_LIB)libprintf

clean :
	@${RM} ${OBJS}
	@${RM} ${P_OBJS}
	@printf "$(YELLOW)$(BOLD)All ${NAME} object files removed$(RESET)\n"
	@printf "$(YELLOW)$(BOLD)All ${NAME} object folders removed$(RESET)\n"

fclean :
	@${MAKE}	clean
	@${RM} ${NAME} 
	@$(MAKE) fclean -C ${P_LFT}
	@$(MAKE) fclean -C ${P_LPF}
	@printf "$(RED)$(BOLD)Binary $(NAME) removed $(RESET)\n"

re :
	@${MAKE} fclean
	@${MAKE} all