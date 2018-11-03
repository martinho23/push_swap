/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:49:47 by jfarinha          #+#    #+#             */
/*   Updated: 2018/09/15 18:57:16 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H
 #include "../includes/libft.h"
 #include <stdlib.h>
 /*
 **Macros
 */
 #define AB 0
 #define A 1
 #define B 2
 /*
 **Structs data
 */
 typedef struct		s_stack
 {
	int				val;
	struct s_stack	*next;
 }					t_stack;
typedef struct		s_memory
 {
	t_stack			*a;
	t_stack			*b;
	size_t		size_a;
	size_t		size_b;
	int			min;
	int			max;
 }					t_memory;
 /*
 **	stack.c
 */
 t_stack			*new(int val);
 void				delval(t_stack **val_to_del);
 void				add(t_stack **stack, int val);
 void				delall(t_stack **stack_to_del);
 void				push_back(t_stack **stack, int val);
 /*
 **	functions_base.c
 */
 void				swap(t_stack *stack);
 void				rotate(t_stack **stack);
 void				revrot(t_stack **stack);
 void				pop(t_stack **popinto, t_stack **popout);
 /*
 **utils.c
 */
 void				error_msg(int b);
 void				ko_msg(int b);
 int				checker(t_memory *memory);
 int				chk_order(t_memory *memory);
 /*
 **load.c
 */
 t_stack			*load_stack(int argc, char **argv);
 void				get_info(t_memory *memory);
 /*
 **func_handlers.c
 */
 void				pop_handler(char *cmd, t_memory *stack);
 void				swap_handler(char *cmd, t_memory *stack);
 void				revrot_handler(char *cmd, t_memory *stack);
 void				rotate_handler(char *cmd, t_memory *stack);
 /*
 **print_cmd.c
 */
 int				print_swap(t_memory *memory, int b);
 int				print_pop(t_memory *memory, int b);
 int				print_rot(t_memory *memory, int b);
 int				print_rev(t_memory *memory, int b);
#endif
