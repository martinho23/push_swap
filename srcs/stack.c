/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:54:27 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/22 11:31:51 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/push_swap.h"

t_stack		*new(int val)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (tmp != NULL)
	{
		tmp->val = val;
		tmp->next = NULL;
	}
	return (tmp);
}

void		add(t_stack **stack, int val)
{
	t_stack	*tmp;

	tmp = new(val);
	if (tmp)
	{
		tmp->next = *stack;
		*stack = tmp;
	}
}

void		delall(t_stack **stack_to_del)
{
	t_stack	*tmp;

	while (*stack_to_del)
	{
		tmp = *stack_to_del;
		*stack_to_del = (*stack_to_del)->next;
		ft_memdel((void **)&tmp);
	}
}

void		delval(t_stack **val_to_del)
{
	t_stack	*tmp;

	if (val_to_del && *val_to_del)
	{
		tmp = *val_to_del;
		*val_to_del = (*val_to_del)->next;
		free(tmp);
		tmp = NULL;
	}
}

void		push_back(t_stack **stack, int val)
{
	t_stack	*tmp;

	tmp = new(val);
	if (tmp)
	{
		while (*stack)
			stack = &(*stack)->next;
		*stack = tmp;
	}
}
