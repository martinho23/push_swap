/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 20:32:16 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/22 11:10:09 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "../includes/libft.h"
#include "../includes/push_swap.h"

static	int		douplicate_checker(t_stack *stack)
{
	t_stack *tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->val == tmp->val)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

t_stack			*load_stack(int argc, char **argv)
{
	t_stack		*a;
	intmax_t	tmp;
	int			i;
	int			j;
	char		**vals;

	i = 1;
	j = 0;
	a = NULL;
	while (i < argc)
	{
		vals = ft_strsplit(argv[i], ' ');
		while (vals[j])
		{
			tmp = ft_atoim(vals[j]);
			if (tmp > INTMAX || tmp < INTMIN || !ft_strisint(vals[j]))
				return (NULL);
			push_back(&a, (int)tmp);
			j++;
		}
		i++;
		j = 0;
	}
	error_msg(douplicate_checker(a));
	return (a);
}
