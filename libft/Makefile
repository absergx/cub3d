# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memilio <memilio@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/29 16:48:52 by memilio           #+#    #+#              #
#    Updated: 2020/08/25 15:10:15 by memilio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCS = libft.h
FILES =			ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strnstr.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putnbr_fd.c \
				ft_putendl_fd.c \
				ft_itoa.c \
				get_next_line.c \
				ft_strdup_gnl.c \
				ft_skip_spaces.c
FILES_BONUS =	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c
OBJS = $(FILES:.c=.o)
OBJS_BONUS = $(FILES_BONUS:.c=.o)
FLAGS = -Wall -Wextra -Werror
LIBC = @ar rc

.PHONY: all bonus clean fclean re .c.o

.c.o:
	@gcc ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${INCS}
	${LIBC} $(NAME) $(OBJS)

all: $(NAME)

bonus: $(NAME) $(OBJS_BONUS) ${INCS}
	${LIBC} $(NAME) $(OBJS_BONUS)

clean:
	@/bin/rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@/bin/rm -f $(NAME) $(bonus)

re: fclean all