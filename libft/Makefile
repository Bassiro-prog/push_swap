NAME = libft.a

SRC_FILES = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_substr.c ft_strjoin.c ft_calloc.c ft_strdup.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_atol.c ft_strcmp.c get_next_line.c get_next_line_utils.c

BONUS_FILES = \
	ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c
OBJ = $(SRC_FILES:.c=.o)
BONUS_OBJ = $(BONUS_FILES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "Biblioteca criada: $(NAME)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilado: $<"

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
	@echo "Biblioteca com bônus criada: $(NAME)"

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	@echo "Objetos removidos!"

fclean: clean
	rm -f $(NAME)
	@echo "Biblioteca removida!"

re: fclean all
	@echo " Recompilação concluída!"

.PHONY: all clean fclean re bonus


