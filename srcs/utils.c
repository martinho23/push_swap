/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 06:11:12 by jfarinha          #+#    #+#             */
/*   Updated: 2018/09/16 12:45:49 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>
void	error_msg(int b)
{
	if (b)
	{
		ft_putendl("Error");
		exit(0);
	}
}

void	ko_msg(int b)
{
	if (b)
	{
		ft_putendl("KO");
		exit(0);
	}
}

int			checker(t_memory *memory)
{
	t_stack	*tmp;

	if (memory->b)
		return (1);
	tmp = memory->a;
	while (tmp && tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			chk_order(t_memory *memory)
{
	t_stack *tmp;
	size_t	i;
	int		a;
	int		b;

	tmp = memory->a;
	i = 0;
	if (memory->b)
		return (0);
	while (tmp && tmp->val != memory->min && (i++))
		tmp = tmp->next;
	a = (tmp) ? tmp->val : -1;
	b = (!tmp->next) ? memory->a->val : tmp->next->val;
	if (a > b)
		return (0);
	while (i < memory->size_a)
	{
		if (a > b)
			return (0);
		tmp = (!tmp->next) ? memory->a : tmp->next;
		a = b;
		b = tmp->val;
		i++;
	}
	return (1);
}
