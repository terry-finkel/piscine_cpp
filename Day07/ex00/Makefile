NAME := whatever
CC := clang++ -std=c++98 -pedantic-errors
FLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) *.cpp -o $@

clean:
	/bin/rm -rf $(NAME)

re: clean all
