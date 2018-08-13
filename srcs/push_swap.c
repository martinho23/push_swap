/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 11:32:42 by jfarinha          #+#    #+#             */
/*   Updated: 2018/08/12 12:18:51 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/push_swap.h>

static void		mkswap(t_memory *memory)
{
	if ((memory->a && memory->b) && \
memory->a->val > memory->a->next->val && (memory->a->next->next && memory->\
a->next->next->val > memory->a->val) && memory->b->val > memory->b->next->val \
&& (memory->b->next->next && memory->b->next->next->val > memory->b->val))
		print_swap(memory, AB);
	if ((memory->a && memory->b) && \
memory->a->val > memory->a->next->val && !memory->a->next->next && \
memory->b->val > memory->b->next->val && !memory->b->next->next)
		print_swap(memory, AB);
	if (memory->a && memory->a->val > memory->a->next->val && \
(memory->a->next->next && (memory->a->next->next->val > memory->a->val)))
		print_swap(memory, A);
	else if (memory->a && memory->a->val > memory->a->next->val && \
!memory->a->next->next)
		print_swap(memory, A);
	if (memory->b && memory->b->val > memory->b->next->val && \
(memory->b->next->next && memory->b->next->next->val > memory->b->val))
		print_swap(memory, B);
	else if (memory->b && memory->b->val > memory->b->next->val && \
!memory->b->next->next)
		print_swap(memory, B);
}

int			main(int argc, char **argv)
{
	t_memory	memory;

	memory.a = load_stack(argc, argv);
	memory.b = NULL;
	if (!checker(&memory))
		return (0);
	while (checker(&memory))
	{
		mkswap(&memory);
	}
	return (0);
}
