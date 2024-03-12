CFLAGS := -Wall -Wextra -Werror
CC := cc

PRTF := ft_printf.c \
	ft_putnbr_base_lc.c \
	ft_putnbr_base_uc.c \
	ft_putnbr_u.c \
	ft_putptr.c \
	ft_strlcpy.c \
	ft_putchar_fd_l.c \
	ft_putnbr_fd_l.c \
	ft_putstr_fd_l.c

POBJ := $(PRTF:.c=.o)

NAME := libftprintf.a

all: $(NAME) 

$(NAME): $(POBJ)
	ar rcs $(NAME) $(POBJ)

clean:
	rm -f $(POBJ)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

