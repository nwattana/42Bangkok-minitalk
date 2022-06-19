LIBFT_DIR = libftprintf/ 
LIBFT_PRINT = libftprintf/libftprintf.a
LIBFT_INC = libftprintf/includes/ -Ilibftprintf/libft/

RED=\e[1;31m
GREEN=\e[1;32m
YELLOW=\e[1;33m
BLUE=\e[1;34m
PINK=\e[1;35m
SKYBULE=\e[1;36m
WHITE=\e[1;37m

ENDCOLOR= \e[0m



all:
	@printf "$(RED)%s\e[0m\e[1;32m%s\e[0m\n" "Hello " $(USER)

main:
	@printf "${GREEN}%s${ENDCOLOR}\n" "complie file main"
	@-gcc -Wall -Wextra -Werror -I$(LIBFT_INC) -I$(LIBFT_DIR) main.c $(LIBFT_PRINT) -o main.o
	@-./main.o

cz:
	@printf "${GREEN}%s${ENDCOLOR}\n" "complie file m_server.c client.c"
	@-gcc -Wall -Wextra -Werror -I$(LIBFT_INC) -I$(LIBFT_DIR) m_server.c $(LIBFT_PRINT) -o server
	@gcc -Wall -Wextra -Werror -I$(LIBFT_INC) -I$(LIBFT_DIR) client.c $(LIBFT_PRINT) -o client

mmm:
	@printf "${GREEN}%s${ENDCOLOR}\n" "complie file zclient"
	@-gcc -Wall -Wextra -Werror -I$(LIBFT_INC) -I$(LIBFT_DIR) zclient.c $(LIBFT_PRINT) -o zclient
	@-./zclient

testlib: lib
	@gcc -Wall -Wextra -Werror -I$(LIBFT_INC) -I$(LIBFT_DIR) check-lib.c $(LIBFT_PRINT) -o check-lib.o
	@./check-lib.o "Hello a good day huha:"
	@rm -rf check-lib.o
lib:
	@make -C ${LIBFT_DIR}

debug: lib
	@gcc -Wall -Wextra -Werror -ggdb -I$(LIBFT_INC) -I$(LIBFT_DIR) check-lib.c $(LIBFT_PRINT) -o check-lib.o
	@./check-lib.o "Hello a good day huha:"
clean:
	@rm -rf *.o
	@rm -rf *.dSYM
	@rm -rf *.out
	@rm -rf zclient

role:
	@printf "all main testlib lib debug clean\n"
