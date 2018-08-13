# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/18 08:52:34 by jfarinha          #+#    #+#              #
#    Updated: 2018/07/26 05:25:38 by jfarinha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKERN	:= checker
CHECKERF	:= functions_base	load	stack	utils	checker	func_handlers
CHECKERB	:= $(CHECKERF:=.o)
CHECKERB	:= $(addprefix srcs/, $(CHECKERB))
PUSH_SWN	:= push_swap
PUSH_SWF	:= functions_base	load	stack	utils	push_swap\
			func_handlers		print_cmd
PUSH_SWB	:= $(PUSH_SWF:=.o)
PUSH_SWB	:= $(addprefix srcs/, $(PUSH_SWB))
LIBDIR		:= libft
FLAGS		:= -Wall -Werror -Wextra
LIBN		:= ft
LIB			:= libft.a
INC			:= includes

.PHONY: all clean fclean re output

all:$(CHECKERN) $(PUSH_SWN)

%.o:%.c
	gcc $(FLAGS) -o $@ -I $(INC) -c $<

$(LIBDIR)/$(LIB):
	make -C $(LIBDIR)

$(CHECKERN):$(CHECKERB) $(LIBDIR)/$(LIB)
	gcc $(FLAGS) -o $@ -I $(INC) -L$(LIBDIR) -l$(LIBN) $^

$(PUSH_SWN):$(PUSH_SWB) $(LIBDIR)/$(LIB)
	gcc $(FLAGS) -o $@ -I $(INC) -L$(LIBDIR) -l$(LIBN) $^

clean:
	rm -rf $(CHECKERB)

fclean:clean
	rm -rf $(CHECKERN)

re:fclean all
