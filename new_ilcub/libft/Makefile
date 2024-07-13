NAME = libft.a

HDRS = libft.h

SRCS = ft_isalpha.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_memset.c\
	ft_memcpy.c\
	ft_atoi.c\
    ft_isalnum.c\
    ft_isascii.c\
    ft_isdigit.c\
	ft_isnum_str.c\
	ft_get_matrix_size.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_isprint.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memmove.c\
	ft_strchr.c\
	ft_strcpy.c\
	ft_strrchr.c\
	ft_strdup.c\
	ft_strcmp.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strlcat.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strjoin_free.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	matrixdup.c\
	free_arr.c\
	ft_strndup.c\
	
OBJS = $(SRCS:.c=.o)

BONUS = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \

BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rc
REMOVE = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	$(LIBC) $(NAME) $(BONUS_OBJS)

clean:
	$(REMOVE) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
