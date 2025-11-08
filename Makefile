NAME := push_swap
CHECKER := checker
CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS_PUSH := push_swap.c swap.c push.c rotate.c rev_rotate.c sort.c sort_utils.c stack_utils.c validation.c

SRCS_CHECKER := checker.c swap.c push.c rotate.c rev_rotate.c sort.c sort_utils.c stack_utils.c validation.c checker_utils.c

OBJS_PUSH := $(SRCS_PUSH:.c=.o)
OBJS_CHECKER := $(SRCS_CHECKER:.c=.o)

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

INCLUDES := -I.

all: $(NAME) $(CHECKER)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS_PUSH)
	$(CC) $(CFLAGS) $(OBJS_PUSH) $(LIBFT) -o $(NAME)

$(CHECKER): $(LIBFT) $(OBJS_CHECKER)
	$(CC) $(CFLAGS) $(OBJS_CHECKER) $(LIBFT) -o $(CHECKER)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS_PUSH) $(OBJS_CHECKER)

fclean: clean
	-$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
