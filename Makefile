NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFOLDER = LIBFT

LIBNAME = $(LIBFOLDER)/libft.a

SRCS = pipex.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBNAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIBNAME) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBNAME):
	make -C $(LIBFOLDER)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re