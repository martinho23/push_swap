/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 07:20:28 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/19 19:50:28 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"
#include "../tests/utils.c"

static void	init(void (*f[4])(char*, t_memory*))
{
	f[0] = pop_handler;
	f[1] = swap_handler;
	f[2] = rotate_handler;
	f[3] = revrot_handler;
}

static void	proc_stack(char *cmd, t_memory *memory)
{
	void	(*f[4])(char*, t_memory*);
	int		op;
	size_t	len;

	init(f);
	op = ft_getindice("psr", *cmd);
	error_msg(op == -1);
	len = ft_strlen(cmd);
	error_msg(len != 2 && len != 3);
	if (op == 2 && len == 3)
		f[3](cmd, memory);
	else
		f[op](cmd, memory);
}

static void	checker(t_memory *memory)
{
	ko_msg(memory->b != NULL);
	while (memory->a && memory->a->next)
	{
		ko_msg(memory->a->val > memory->a->next->val);
		memory->a = memory->a->next;
	}
	ft_putendl("OK");
}

int			main(int argc, char **argv)
{
	t_memory	memory;
	char		*cmd;

	memory.a = load_stack(argc, argv);
	memory.b = NULL;
	cmd = NULL;
	print_all(memory.a);
	while (get_next_line(0, &cmd))
	{
		proc_stack(cmd, &memory);
		ft_strdel(&cmd);
	}
	print_all(memory.a);
	print_all(memory.b);
	checker(&memory);
}