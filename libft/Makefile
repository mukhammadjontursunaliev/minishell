# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtursuna <mtursuna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 11:12:32 by mtursuna          #+#    #+#              #
#    Updated: 2024/12/13 20:29:10 by mtursuna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
			ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_isspace.c ft_strncmp.c
			
OBJS = $(SRCS:.c=.o)
BONUS= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJS =$(BONUS:.c=.o)
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all:${NAME}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) ${OBJS} ${BONUS_OBJS}
fclean: clean 
	${RM} $(NAME)

re: fclean all
bonus: ${OBJS} ${BONUS_OBJS} 
	ar rcs ${NAME} ${BONUS_OBJS}

.PHONY: all clean fclean re bonus
