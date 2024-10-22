NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFOLDER = LIBFT
LIBNAME = $(LIBFOLDER)/libft.a

SRCS = pipex.c utils.c get_path.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBNAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIBNAME) -o $(NAME)
	@echo "pipex compiled"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"

$(LIBNAME):
	@make -C $(LIBFOLDER)
	@echo "libft built"

clean:
	rm -f $(OBJS)
	@echo "pipex cleaned"

fclean: clean
	@make -C $(LIBFOLDER) fclean
	@rm -f $(NAME)
	@echo "pipex fully cleaned"

re: fclean all

.PHONY: all clean fclean re
