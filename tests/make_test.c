/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 12:27:38 by jfarinha          #+#    #+#             */
/*   Updated: 2018/09/06 12:57:23 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "../includes/libft.h"

#define PUSH "../push_swap"
#define CHECK "../checker"

void	mk_test(void)
{
	int 	size;
	int	sarr;
	int	indice;
	int	i;
	

	srand(time(NULL));
	size = rand() % 7 + 3;
	indice = 0;
	sarr = 1;
	i = 0;
	int	nbr[size];
	while (i < size)
		nbr[i++] = rand() % INT_MAX;
	i = 0;
	while (i < size)
		sarr += ft_imtoalen_base((intmax_t)nbr[i++], 10) + 1;
	i = 0;
	char	nbrs[sarr];
	while (i < size)
	{
		nbrs[indice++] = ' ';
		indice += ft_uimtoa_base((uintmax_t)nbr[i++], 10, &nbrs[indice], BASE10);
	}
	printf("export ARGS=\"%s\"; echo -n \"Test $ARGS:\"; %s $ARGS | %s $ARGS\n", nbrs, PUSH, CHECK);
}

int	main(int argc, char **argv)
{
	int	testNbr;
	int	i;

	if (argc == 2)
	{
		testNbr = atoi(argv[1]);
		i = 0;
		while (i < testNbr)
		{
			mk_test();
			i++;
		}
		
	}
	else
		printf("Usage: ./makeTest [nbrOfRuns] \n");
	return (0);
}
