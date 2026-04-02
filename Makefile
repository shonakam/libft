# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/29 18:35:50 by shonakam          #+#    #+#              #
#    Updated: 2025/02/27 05:35:01 by shonakam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname -s)
NAME := libft.a
CC ?= cc

DEBUG ?= 0

ifeq ($(DEBUG), 1)
	OBJS_DIR	:= .out_debug
	MODE_FLAGS	:= -g3 -O0 -DDEBUG_MODE -fsanitize=address
	MODE_MSG	:= "Debug Mode No Optimization, GDB ready"
else
	OBJS_DIR	:= .out
	MODE_FLAGS	:= -O3
	MODE_MSG	:= "Release Mode High Optimization"
endif

CFLAGS  := -Wall -Wextra -Werror -pedantic -fno-builtin $(MODE_FLAGS)

SRCS := ft_atoi.c \
        ft_bzero.c \
        ft_calloc.c \
        ft_isalnum.c \
        ft_isalpha.c \
        ft_isascii.c \
        ft_isdigit.c \
        ft_isprint.c \
        ft_memchr.c \
        ft_memcmp.c \
        ft_memcpy.c \
        ft_memmove.c \
        ft_memset.c \
        ft_strchr.c \
        ft_strlen.c \
        ft_strlcpy.c \
        ft_strlcat.c \
        ft_strrchr.c \
        ft_strnstr.c \
        ft_strncmp.c \
        ft_toupper.c \
        ft_tolower.c \
        ft_strdup.c \
        ft_substr.c \
        ft_strjoin.c \
        ft_strtrim.c \
        ft_split.c \
        ft_itoa.c \
        ft_strmapi.c \
        ft_striteri.c \
        ft_putchar_fd.c \
        ft_putstr_fd.c \
        ft_putendl_fd.c \
        ft_putnbr_fd.c \
        ft_atoll.c \
        ft_is_whitespace.c \
        ft_is_plus_minus.c \
        ft_is_digit.c \

SRCS_BONUS  = ft_lstadd_back.c \
              ft_lstadd_front.c \
              ft_lstclear.c \
              ft_lstdelone.c \
              ft_lstiter.c \
              ft_lstlast.c \
              ft_lstmap.c \
              ft_lstnew.c \
              ft_lstsize.c

SRCS_PF := ft_printf/ft_printf.c ft_printf/ft_conversion.c ft_printf/utils.c
SRCS_GNL := get_next_line/get_next_line.c

ALL_SRCS := $(SRCS) $(SRCS_BONUS) $(SRCS_PF) $(SRCS_GNL)

OBJS := $(addprefix $(OBJS_DIR)/, $(ALL_SRCS:.c=.o))

.PHONY: all clean fclean re bounus check list

all:
	@echo "Building: $(MODE_MSG)"
	@$(MAKE) $(NAME) DEBUG=$(DEBUG) -j $(shell nproc)

bonus: all

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "✓ $(NAME) created with all modules (Libft, List, Printf, GNL)."

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf .out .out_debug

fclean: clean
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all DEBUG=$(DEBUG)


# --- Diagnostic Tools ---
.PHONY: mode_check check list debug

mode_check:
	@echo "Checking for debug symbols in $(NAME)..."
	@nm $(NAME) | grep -qE "__asan_|__sanitizer_" && \
		echo "YES (ASan/Debug Enabled)" || echo "NO (Release Mode)"

check:
	@printf "\033[32m[Checking symbols...]\033[0m\n"
	nm $(NAME) | grep " T " | sed 's/.* _//'

list:
	@printf "\033[34m[Listing objects...]\033[0m\n"
	ar -t $(NAME)

debug:
	@printf "\033[35m[Makefile Variables]\033[0m\n"
	@echo "NAME: $(NAME)"
	@echo "OBJS: $(words $(OBJS)) files"
