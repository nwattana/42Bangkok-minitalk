LIBFT_DIR = libftprintf/
LIBFT_PRINT = libftprintf/libftprintf.a
LIBFT_INC = libftprintf/includes

RED= \e[1;31m
GREEN= \e[1;32m

ENDCOLOR= \e[0m




all:
	@printf "$(RED)%s\e[0m\e[1;32m%s\e[0m\n" "Hello " "TENT"

main:
	@printf "${GREEN}%s${ENDCOLOR}\n" "complie file main"
	@gcc -Wall -Wextra -Werror -I$(LIBFT_INC) -I$(LIBFT_DIR) main.c $(LIBFT_PRINT) -o main.o
	@./main.o


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

role:
	printf "all main testlib lib debug clean\n"
