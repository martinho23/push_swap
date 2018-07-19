/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:51:07 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/19 17:46:46 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
	t_stack	*tmp;
	int		tmp_val;

	if (stack)
		tmp = stack->next;
	if(tmp && stack)
	{
		tmp_val = stack->val;
		stack->val = tmp->val;
		tmp->val = tmp_val;
	}
}

void	pop(t_stack **popinto, t_stack **popout)
{
	if (popinto && popout && *popout)
	{
		add(popinto, (*popout)->val);
		delval(popout);
	}
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (stack &&  *stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		while ((*stack)->next)
			stack = &(*stack)->next;
		(*stack)->next = tmp;
	}
}

void	revrot(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	if (stack && *stack && (*stack)->next)
	{
		current = (*stack)->next;
		tmp = *stack;
		while (current->next)
		{
			current = current->next;
			tmp = tmp->next;
		}
		current->next = *stack;
		*stack = current;
		tmp->next = NULL;
	}
}
