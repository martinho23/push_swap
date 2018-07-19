# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/18 08:52:34 by jfarinha          #+#    #+#              #
#    Updated: 2018/07/19 07:00:53 by jfarinha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKERN	:= checker
CHECKERF	 :=functions_base	load	stack	utils	checker	func_handlers
CHECKERB	:= $(CHECKERF:=.o)
CHECKERB	:= $(addprefix srcs/, $(CHECKERB))
LIBDIR		:= libft
FLAGS		:= -Wall -Werror -Wextra
LIBN		:= ft
LIB			:= libft.a
INC			:= includes

.PHONY: all clean fclean re output

all:$(CHECKERN)

%.o:%.c
	gcc $(FLAGS) -o $@ -I $(INC) -c $<

$(LIBDIR)/$(LIB):
	make -C $(LIBDIR)

$(CHECKERN):$(CHECKERB) $(LIBDIR)/$(LIB)
	gcc $(FLAGS) -o $@ -I $(INC) -L$(LIBDIR) -l$(LIBN) $^

clean:
	rm -rf $(CHECKERB)

fclean:clean
	rm -rf $(CHECKERN)

re:fclean all
