/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 06:32:54 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/19 19:49:03 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_handler(char *cmd, t_memory *stack)
{
	int		op;

	error_msg(ft_strlen(cmd) != 2);
	cmd++;
	op = ft_getindice("abs", *cmd);
	error_msg(op == -1);
	if (op == 0)
		swap(stack->a);
	else if (op == 1)
		swap(stack->b);
	else
	{
		swap(stack->a);
		swap(stack->b);
	}
}

void	pop_handler(char *cmd, t_memory *stack)
{
	int		op;

	error_msg(ft_strlen(cmd) != 2);
	cmd++;
	op = ft_getindice("ab", *cmd);
	error_msg(op == -1);
	if (op == 0)
		pop(&stack->a, &stack->b);
	else
		pop(&stack->b, &stack->a);
}

void	rotate_handler(char *cmd, t_memory *stack)
{
	int		op;

	error_msg(ft_strlen(cmd) != 2);
	cmd++;
	op = ft_getindice("abr", *cmd);
	error_msg(op == -1);
	if (op == 0)
		rotate(&stack->a);
	else if (op == 1)
		rotate(&stack->b);
	else
	{
		rotate(&stack->a);
		rotate(&stack->b);
	}
}

void	revrot_handler(char *cmd, t_memory *stack)
{
	int		op;

	error_msg(ft_strlen(cmd) != 3);
	cmd += 2;
	op = ft_getindice("abr", *cmd);
	error_msg(op == -1);
	if (op == 0)
		revrot(&stack->a);
	else if (op == 1)
		revrot(&stack->b);
	else
	{
		revrot(&stack->a);
		revrot(&stack->b);
	}
}
