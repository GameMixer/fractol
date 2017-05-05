# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/28 19:09:15 by gderenzi          #+#    #+#              #
#    Updated: 2017/05/04 11:08:41 by gderenzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
CFLAGS		+= -I includes/ -I libft/includes -I mlx/ 
LDFLAGS		:= -L libft/ -lft -L mlx/ -lmlx -framework OpenGL -framework AppKit
SRC			= main.c

OBJ			= $(addprefix $(OBJDIR),$(SRC:.c=.o))

LIBFT		= libft/libft.a
LIBMLX		= mlx/libmlx.a

SRCDIR		= ./src/
INCDIR		= ./includes/
OBJDIR		= ./obj/

all: $(NAME)


$(LIBFT):
	$(MAKE) -C libft 

$(LIBMLX):
	@make -C mlx

$(addprefix $(OBJDIR), %.o): $(addprefix $(SRCDIR), %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ 

clean:
	$(MAKE) -C libft clean
	make -C mlx clean
	@rm -f $(OBJ)
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all
