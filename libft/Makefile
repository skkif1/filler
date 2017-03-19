CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCFLS =   ft_append.c \
          ft_atoi.c \
          ft_bzero.c \
          ft_isalnum.c \
          ft_isalpha.c \
          ft_isascii.c \
          ft_isdigit.c \
          ft_isprint.c \
          ft_itoa.c \
          ft_lstadd.c \
          ft_lstadd_end.c \
          ft_lstdel.c \
          ft_lstdelone.c \
          ft_lstiter.c \
          ft_lstmap.c \
          ft_lstnew.c  \
          ft_memalloc.c       \
          ft_memccpy.c     \
          ft_memchr.c         \
          ft_memcmp.c     \
          ft_memcpy.c     \
          ft_memdel.c     \
          ft_memmove.c     \
          ft_memset.c     \
          ft_putchar.c     \
          ft_putchar_fd.c     \
          ft_putendl.c    \
          ft_putendl_fd.c     \
          ft_putnbr.c     \
          ft_putnbr_fd.c     \
          ft_putstr.c    \
          ft_putstr_fd.c    \
          ft_strcat.c     \
          ft_strchr.c     \
          ft_strclr.c     \
          ft_strcmp.c     \
          ft_strcpy.c     \
          ft_strdel.c     \
          ft_strdup.c     \
          ft_strequ.c     \
          ft_striter.c     \
          ft_striteri.c     \
          ft_strjoin.c     \
          ft_strlcat.c     \
          ft_strlen.c     \
          ft_strmap.c     \
          ft_strmapi.c     \
          ft_strncat.c     \
          ft_strncmp.c     \
          ft_strncpy.c     \
          ft_strnequ.c     \
          ft_strnew.c     \
          ft_strnstr.c     \
          ft_strrchr.c     \
          ft_strsplit.c     \
          ft_strstr.c     \
          ft_strsub.c     \
          ft_strtrim.c     \
          ft_tolower.c     \
          ft_toupper.c     \
          ft_renew.c \
          ft_redup.c \
          ft_lstsort.c \
          get_next_line.c \

PRINTF_SRC = ft_printf.c get_modif.c num_list.c number.c number_handler.c \
parse.c str_handler.c string.c char_handler.c util.c wide_str.c util_bonus.c

PRINTF_OBJ = $(subst .c,.o,$(PRINTF_SRC))
OBJECTS = $(subst .c,.o,$(SRCFLS))
SRC_C = $(SRCFLS) $(PRINTF_SRC)
SRC_O = $(SRC_C:.c=.o) $(PRINTF_OBJ)
all: $(NAME)

$(NAME): $(SRC_O)
	ar rc $(NAME) $(SRC_O)
	ranlib $(NAME)

$(OBJECT): $(SRC_C)
	gcc -Wall -Wextra -Werror -c $(SRC_C)
clean:
	/bin/rm -f $(SRC_O)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
