/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 11:32:42 by jfarinha          #+#    #+#             */
/*   Updated: 2018/09/16 12:47:20 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include "../tests/utils.c"

static int		mkswap(t_memory *mem)
{
	if ((mem->size_a > 2 && mem->size_b > 2) && \
mem->a->val > mem->a->next->val && mem->\
a->next->next->val > mem->a->val && mem->b->val > mem->b->next->val \
&& mem->b->next->next->val > mem->b->val)
		return (print_swap(mem, AB));
	if ((mem->size_a > 2) && mem->a->val > mem->a->next->val\
&& (mem->a->next->next && (mem->a->next->next->val > mem->a->val)))
		return (print_swap(mem, A));
	if ((mem->size_b > 2) && mem->b->val > mem->b->next->val\
&& mem->b->next->next->val > mem->b->val)
		return (print_swap(mem, B));
	return (0);
}

static int		mkpop(t_memory *mem)
{
	if ((mem->a && mem->a->next && mem->a->val != mem->min && mem->a->val != mem->max) && mem->a->val > \
mem->a->next->val)
		return (print_pop(mem, B));
	if (mem->b && !mem->a)
		return (print_pop(mem, A));
	if (mem->b && mem->a && mem->b->val < mem->a->val)
		return (print_pop(mem, A));
	return (0);
}

static void		mkrot(t_memory *mem)
{
	print_rot(mem, A);
}

int				main(int argc, char **argv)
{
	t_memory	mem;

	mem.a = load_stack(argc, argv);
	mem.b = NULL;
	get_info(&mem);
	if (!checker(&mem))
		return (0);
	while (!chk_order(&mem))
	{
		/*printf("A\n");
		print_all(mem.a);
		printf("B\n");
		print_all(mem.b);*/
		if (!mkswap(&mem))
			if (!mkpop(&mem))
				mkrot(&mem);
	}
	while (checker(&mem))
	{
/*		printf("A\n");
		print_all(mem.a);
		printf("B\n");
		print_all(mem.b);*/
		print_rot(&mem, A);
	}
	return (0);
}
