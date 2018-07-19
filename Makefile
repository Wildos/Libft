#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 17:37:32 by tfernand          #+#    #+#              #
#    Updated: 2018/07/19 12:14:27 by tfernand         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

INCLUDES_DIR = includes
SOURCES_DIR = sources
OBJS_DIR = objs

OBJS = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o \
	ft_memchr.o ft_memcmp.o ft_strcpy.o ft_strdup.o ft_strlen.o ft_strncpy.o \
	ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strstr.o \
	ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o \
	ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o \
	ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o \
	ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o \
	ft_strsub.o ft_strjoin.o ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o \
	ft_putstr.o ft_putendl.o ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o \
	ft_putendl_fd.o ft_putnbr_fd.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o \
	ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_iswhite.o ft_count_word.o \
	get_next_line.o

ifneq ($(words $(MAKECMDGOALS)), 1) # if no argument was given to make...
.DEFAULT_GOAL = all # set the default goal to all
%: # define a last resort default rule
	@$(MAKE) $@ --no-print-directory -rRf $(firstword $(MAKEFILE_LIST)) # recursive make call,
else
ifndef PRINTF
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
	-nrRf $(firstword $(MAKEFILE_LIST)) \
	PRINTF="COUNTTHIS" | grep -c "COUNTTHIS")
N := x
C = $(words $N)$(eval N := x $N)
PRINTF = printf "[%3d%%] linking %s\n\033[1A" `expr $C '*' 100 / $T`
endif

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(addprefix $(OBJS_DIR)/, $(OBJS))
	@ar rc $(NAME) $^
	@ranlib $(NAME)
	@echo "\033[2K### $@ done. ###"

$(OBJS_DIR)/%.o: $(SOURCES_DIR)/%.c $(INCLUDES_DIR)/libft.h | $(OBJS_DIR)
	@gcc $(FLAGS) -o $@ -c $< -I $(INCLUDES_DIR)
	@$(PRINTF) $(notdir $@)

$(OBJS_DIR):
	mkdir $@

clean:
	-rm -f $(addprefix $(OBJS_DIR)/, $(OBJS))

fclean:
	@make clean
	-rm -f $(NAME)

re:
	@make fclean
	@make all
endif