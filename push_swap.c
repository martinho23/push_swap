/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 11:32:42 by jfarinha          #+#    #+#             */
/*   Updated: 2018/08/23 07:36:27 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/push_swap.h>

static int		mkswap(t_memory *memory)
{
	if ((memory->a && memory->b) && \
memory->a->val > memory->a->next->val && (memory->a->next->next && memory->\
a->next->next->val > memory->a->val) && memory->b->val > memory->b->next->val \
&& (memory->b->next->next && memory->b->next->next->val > memory->b->val))
		return (print_swap(memory, AB));
	if ((memory->a && memory->b) && \
memory->a->val > memory->a->next->val && !memory->a->next->next && \
memory->b->val > memory->b->next->val && !memory->b->next->next)
		return (print_swap(memory, AB));
	if (memory->a && memory->a->val > memory->a->next->val && \
(memory->a->next->next && (memory->a->next->next->val > memory->a->val)))
		return (print_swap(memory, A));
	else if (memory->a && memory->a->val > memory->a->next->val && \
!memory->a->next->next)
		return (print_swap(memory, A));
	if (memory->b && memory->b->val > memory->b->next->val && \
(memory->b->next->next && memory->b->next->next->val > memory->b->val))
		return (print_swap(memory, B));
	else if (memory->b && memory->b->val > memory->b->next->val && \
!memory->b->next->next)
		return (print_swap(memory, B));
	return (0);
}

static int		mkpop(t_memory *memory)
{
	if ((memory->a && memory->a->next) && memory->a->val > \
memory->a->next->val)
		return (print_pop(memory, B));
	if (memory->b && !memory->a)
		return (print_pop(memory, A));
	if (memory->b && memory->a && memory->b->val < memory->a->val)
		return (print_pop(memory, A));
	return (0);
}

static int		mkrot(t_memory *memory)
{
	while (memory->a && memory->b && memory->a->next && memory->a->val\
< memory->a->next->val && memory->b->val > memory->a->val)
		return (print_rot(memory, AB));
	while (memory->a && memory->a->next && memory->a->val < \
memory->a->next->val)
		return (print_rot(memory, A));
	while (memory->a && memory->a->next && memory->b && memory->b->val > memory->a->val)
		return (print_rot(memory, B));
	return (0);
}

int				main(int argc, char **argv)
{
	t_memory	memory;

	memory.a = load_stack(argc, argv);
	memory.b = NULL;
	if (!checker(&memory))
		return (0);
	while (checker(&memory))
	{
		if (!mkswap(&memory))
			if (!mkpop(&memory))
				mkrot(&memory);
	}
	return (0);
}
