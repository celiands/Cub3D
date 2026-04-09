# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 09:04:41 by ngauthre          #+#    #+#              #
#    Updated: 2025/10/27 09:04:41 by ngauthre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Flags = -Wall -Werror -Wextra #-O3
OBJPATH = src/obj
src = src/animation.c src/colisions.c src/cub3d_utils.c src/cub3d.c src/dda.c src/ft_test.c src/hooks.c src/hooks2.c src/img.c src/init.c src/list_utils1.c src/list_utils2.c src/map1.c src/map2.c src/map3.c src/op_vect.c src/opti_utils.c src/player1.c src/player2.c src/raycasting.c src/raycasting2.c src/raycasting3.c src/render.c src/render2.c src/UV.c
libft_src = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_lstadd_back_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstclear_bonus.c libft/ft_lstdelone_bonus.c libft/ft_lstiter_bonus.c libft/ft_lstlast_bonus.c libft/ft_lstmap_bonus.c libft/ft_lstnew_bonus.c libft/ft_lstsize_bonus.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_print_pxX.c libft/ft_print_scdiu.c libft/ft_printf.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c libft/get_next_line.c libft/get_next_line_utils.c 

obj = $(src:src/%.c=$(OBJPATH)/%.o)
NAME = cub3d
libx = minilibx-linux/libmlx.a
libft = libft/libft.a
headers = cub3d.h
CC = cc

RED	= \033[0;31m
GREEN = \033[0;32m
BLUE  = \033[0;34m
YELLOW = \033[1;33m
RESET = \033[0m

all : $(NAME)

$(NAME) : $(obj) $(libx) $(libft)
	@echo "$(GREEN) ❈ Compilation in progress...$(RESET)" 
	@$(CC) $(obj) $(libx) $(libft) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) && \
	echo "$(YELLOW) ► $@ has been compiled ✔$(RESET)" || \
	(echo "$(RED) Failed : $@ $(RESET)" && exit 1)

$(libx) :
	@make -C minilibx-linux --no-print-directory > /dev/null 2>&1

$(libft) : libft/libft.h $(libft_src)
	@make -C libft --no-print-directory

$(OBJPATH)/%.o : src/%.c $(headers)
	@mkdir -p src/obj
	@$(CC) $(Flags) -I/usr/include -Imlx_linux -c $< -o $@ -I . && \
	echo "$(BLUE)  ╰┈➤ $@ : Compiled ✔$(RESET)" || \
	(echo "$(RED) Failed : $@ $(RESET)" && exit 1)
	
clean :
	@echo "$(RED) ☒ Cleaning in progress... $(RESET)" 
	@rm -f $(obj)
	@make -C minilibx-linux clean --no-print-directory > /dev/null 2>&1
	@make -C libft clean --no-print-directory
	@echo "$(GREEN) ♣ Cleaning ✔ $(RESET)" 

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(libx)
	@make -C libft fclean --no-print-directory
	@echo "$(RED)  ╰┈➤ $(NAME) : removed ✔$(RESET)"

re : fclean all

.PHONY: all re clean fclean