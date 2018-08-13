/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 05:12:32 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/26 05:31:24 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_swap(t_memory *memory, int b)
{
	if (b == AB)
	{
		swap(memory->a);
		swap(memory->b);
		ft_putendl("ss");
	}
	else if (b == A)
	{
		swap(memory->a);
		ft_putendl("sa");
	}
	else if (b == B)
	{
		swap(memory->b);
		ft_putendl("sb");
	}
}

void	print_pop(t_memory *memory, int b)
{
	if (b == A)
	{
		pop(&memory->a, &memory->b);
		ft_putendl("pa");
	}
	else if (b == B)
	{
		pop(&memory->b, &memory->a);
		ft_putendl("pb");
	}
}

void	print_rot(t_memory *memory, int b)
{
	if (b == AB)
	{
		rotate(&memory->a);
		rotate(&memory->b);
		ft_putendl("rr");
	}
	else if (b == A)
	{
		rotate(&memory->a);
		ft_putendl("ra");
	}
	else if (b == B)
	{
		rotate(&memory->b);
		ft_putendl("rb");
	}
}

void	print_rev(t_memory *memory, int b)
{
	if (b == AB)
	{
		revrot(&memory->a);
		revrot(&memory->b);
		ft_putendl("rrr");
	}
	else if (b == A)
	{
		revrot(&memory->a);
		ft_putendl("rra");
	}
	else if (b == B)
	{
		revrot(&memory->b);
		ft_putendl("rrb");
	}
}
