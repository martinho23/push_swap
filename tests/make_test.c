/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 12:27:38 by jfarinha          #+#    #+#             */
/*   Updated: 2018/11/03 18:29:51 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "../includes/libft.h"

#define PUSH "../push_swap"
#define CHECK "../checker"

void	mk_test(int testIndice)
{
	int 	size;
	int	sarr;
	int	indice;
	int	i;
	int j;

	size = 100;
	indice = 0;
	sarr = 1;
	i = 0;
	int	nbr[size];
	while (i < size)
		nbr[i++] = rand() % 100;
	j = 0;
	while (i > 0)
	{
		while (j < i)
			if (nbr[i] == nbr[j++])
			{
				nbr[j - 1] = rand() % 100;
				i = size;
				j = 0;
			}
		i--;
		j = 0;
	}
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
	printf("export ARGS=\"%-100s\"; echo -n \"Test %d $ARGS: \"; %s $ARGS | %s $ARGS\n", nbrs, testIndice, PUSH, CHECK);
	printf("export ARGS=\"%-100s\"; echo -n \"Test %d $ARGS: \"; %s $ARGS | wc -l\n", nbrs, testIndice, PUSH);
}

int	main(int argc, char **argv)
{
	int	testNbr;
	int	i;

	if (argc == 2)
	{
		srand(time(NULL));
		testNbr = atoi(argv[1]);
		i = 0;
		while (i < testNbr)
		{
			mk_test(i);
			i++;
		}
	}
	else
		printf("Usage: ./makeTest [nbrOfRuns] \n");
	return (0);
}
