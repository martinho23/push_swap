/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 06:11:12 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/19 17:39:09 by jfarinha         ###   ########.fr       */
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
