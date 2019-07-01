/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyvchyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:06:05 by anyvchyk          #+#    #+#             */
/*   Updated: 2019/07/01 13:06:07 by anyvchyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libls.h"

static void 		parse_mode(const char *mod)
{
	short			i;

	i = 1;
	(mod[0] == '4') ? ft_printf("d") : ft_printf("-");
	while (mod[i] == 48 && i <=2)
		i++;
	while (mod[i])
	{
		if (mod[i] == '0')
			write(1, "---", 3);
		if (mod[i] == '1')
			write(1, "--x", 3);
		if (mod[i] == '2')
			write(1, "-w-", 3);
		if (mod[i] == '3')
			write(1, "-wx", 3);
		if (mod[i] == '4')
			write(1, "r--", 3);
		if (mod[i] == '5')
			write(1, "r-x", 3);
		if (mod[i] == '6')
			write(1, "rw-", 3);
		if (mod[i] == '7')
			write(1, "rwx", 3);
		i++;
	}
	write(1, "\t", 1);
}

static void			show_mode(const t_list *node)
{
	struct stat		buf;
	char			*mod;
	short			i;

	stat(node->name, &buf);
	i = 1;
	mod = ft_itoa_base_signed(buf.st_mode, 8);
	parse_mode(mod);
	free(mod);
}

void				show_long_list(t_list **head)
{
	t_list	*curr;

	curr = *head;
	//show total func
	while (curr)
	{
		show_mode(curr);
		ft_printf(GREEN "%s\n" WHITE, curr->name);
		curr = curr->next;
	}
}
