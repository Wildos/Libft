#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 14:59:28 by tfernand          #+#    #+#              #
#    Updated: 2018/10/08 14:59:29 by tfernand         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC_PATH = ./srcs/

SRC_PRINTF_PATH = ./srcs_printf/

OBJ_PATH = ./objs/

INCLUDE_PATH = ./includes/

SRC_NAME = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o \
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

SRC_PRINTF_NAME = ft_printf.o ft_buffer_modification.o ft_flags_identification.o ft_flags_recuperation.o ft_value_to_buffer.o ft_bzero.o ft_isdigit.o ft_strlen.o ft_integer_to_buffer.o ft_number_to_buffer.o ft_apply_width_and_precision.o ft_unsigned_to_buffer.o ft_onumber_to_buffer.o ft_xnumber_to_buffer.o ft_pointer_to_buffer.o ft_pourcent_to_buffer.o ft_single_char_to_buffer.o ft_unicode_char_to_buffer.o ft_string_to_buffer.o ft_binary_to_buffer.o

INCLUDE_SRC_NAME = libft.h \
		get_next_line.h

INCLUDE_PRINTF_NAME = ft_printf.h

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PRINTF_NAME = $(SRC_PRINTF_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME) \
				$(SRC_PRINTF_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME) $(OBJ_PRINTF_NAME))

HEADER_SRC = $(addprefix $(INCLUDE_PATH), $(INCLUDE_SRC_NAME))

HEADER_SRC_PRINTF = $(addprefix $(INCLUDE_PATH), $(INCLUDE_SRC_NAME) $(INCLUDE_PRINTF_NAME))

INCLUDE = -I$(INCLUDE_PATH)

FLAGS = -Wall -Werror -Wextra

.PHONY: all, clean, fclean, re, norminette

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER_SRC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(FLAGS) $(INCLUDE) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_PRINTF_PATH)%.c $(HEADER_SRC_PRINTF)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(FLAGS) $(INCLUDE) -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norminette:
	norminette $(INCLUDE_PATH)
	norminette $(SRC_PATH)
	norminette $(SRC_PRINTF_PATH)
