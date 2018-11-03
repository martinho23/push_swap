/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 23:51:44 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/15 09:29:32 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"

int main(void)
{
	t_stack	*a;
	t_stack	**tmp;
	int		i;

	i = 0;
	printf("New Stack\n");
	a = new(0);
	i = 0;
	tmp = &a;
	printf("Stack Add 0\n");
	while (i < 4)
	{
		add(&a, i + 1);
		printf("Stack Add %d\n", i + 1);
		i++;
	}
	i = 0;
	tmp = &a;
	while (*tmp)
	{
		printf("Stack Values After Adding them %d\n", (*tmp)->val);
		tmp = &(*tmp)->next;
	}
	i = 0;
	tmp = &a;
	while (i < 4)
	{
		tmp = &(*tmp)->next;
		i++;
	}
	delval(tmp);
	if (*tmp)
		printf("Tmp val after del val 3 %d\n", (*tmp)->val);
	delall(&a);
	if (a == NULL)
		printf("Stack Totally deleted\n");
	else
		printf("Stack not deleted\n");
	printf("delval NULL\n");
	delval(&a);
	printf("delall NULL\n");
	delall(&a);
	printf("add to NULL\n");
	add(&a, 42);
	printf("Value after add %d\n", a->val);
	if (!a->next)
		printf("List NULL terminated after add :3\n");
	else
		printf("List non NULL terminated after add ;-;\n");
	return (0);
}
