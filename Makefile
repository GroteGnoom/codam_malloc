ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
SRC = malloc.c
INC = malloc.h

ifdef DEBUG
	CC=clang
	ASAN_OPTIONS='detect_leaks=1'
	FLAGS = -Wall -Wextra -fsanitize=address -fsanitize=undefined -DDEBUG=1 -g
else
	CC=gcc
	FLAGS = -Wall -Wextra -Werror
endif

OBJ = $(SRC:.c=.o)

all: $(NAME) libft_malloc.so

libft_malloc.so:
	ln -s libft_malloc_x86_64_Darwin.so libft_malloc.so

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -dynamiclib -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

test: main.c all
	$(CC) $(FLAGS) $< -o $@ $(NAME)
	#install_name_tool -change "@loader_path/$(NAME)" "./$(NAME)" main.o
	#$(CC) $(FLAGS) $< -o $@ -L. -l./$(NAME)

re: fclean all
.PHONY: all clean fclean 
