/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 05:12:32 by jfarinha          #+#    #+#             */
/*   Updated: 2018/08/23 07:12:34 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		print_swap(t_memory *memory, int b)
{
	if (b == AB)
	{
		swap(memory->a);
		swap(memory->b);
		ft_putendl("ss");
		return (1);
	}
	else if (b == A)
	{
		swap(memory->a);
		ft_putendl("sa");
		return (1);
	}
	else if (b == B)
	{
		swap(memory->b);
		ft_putendl("sb");
		return (1);
	}
	return (0);
}

int		print_pop(t_memory *memory, int b)
{
	if (b == A)
	{
		pop(&memory->a, &memory->b);
		ft_putendl("pa");
		return (1);
	}
	else if (b == B)
	{
		pop(&memory->b, &memory->a);
		ft_putendl("pb");
		return (1);
	}
	return (0);
}

int		print_rot(t_memory *memory, int b)
{
	if (b == AB)
	{
		rotate(&memory->a);
		rotate(&memory->b);
		ft_putendl("rr");
		return (1);
	}
	else if (b == A)
	{
		rotate(&memory->a);
		ft_putendl("ra");
		return (1);
	}
	else if (b == B)
	{
		rotate(&memory->b);
		ft_putendl("rb");
		return (1);
	}
	return (0);
}

int		print_rev(t_memory *memory, int b)
{
	if (b == AB)
	{
		revrot(&memory->a);
		revrot(&memory->b);
		ft_putendl("rrr");
		return (1);
	}
	else if (b == A)
	{
		revrot(&memory->a);
		ft_putendl("rra");
		return (1);
	}
	else if (b == B)
	{
		revrot(&memory->b);
		ft_putendl("rrb");
		return (1);
	}
	return (0);
}
