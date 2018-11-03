/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 06:11:12 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/22 13:13:21 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

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
	ko_msg(memory->b != NULL);
	while (memory->a && memory->a->next)
	{
		if (memory->a->val > memory->a->next->val)
			return (1);
		memory->a = memory->a->next;
	}
	return (0);
}
