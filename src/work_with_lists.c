/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyvchyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 08:52:12 by anyvchyk          #+#    #+#             */
/*   Updated: 2019/06/27 08:52:14 by anyvchyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libls.h"

void				push(t_list **head_ref, char *new_data, char *path)
{
	t_list			*new_node;

	new_node = (t_list*)malloc(sizeof(t_list));
	new_node->name = ft_strdup(new_data);
	new_node->path = ft_strjoin(path, "/");
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void				show_list(t_list **head)
{
	t_list			*curr;

	curr = *head;
	while (curr)
	{
		ft_printf(GREEN "\t%s\n" WHITE, curr->name);
		curr = curr->next;
	}
}

void				delete_list(t_list **head_ref)
{
	t_list			*current;
	t_list			*next;

	current = *head_ref;
	while (current != NULL)
	{
		next = current->next;
		free(current->name);
		free(current->path);
		free(current);
		current = next;
	}
	*head_ref = NULL;
}

void				reverse_list(t_list **head_ref)
{
	t_list			*first;
	t_list			*rest;

	if (*head_ref == NULL)
		return ;
	first = *head_ref;
	rest = first->next;
	if (rest == NULL)
		return ;
	reverse_list(&rest);
	first->next->next = first;
	first->next = NULL;
	*head_ref = rest;
}

void				show_total(t_list **head)
{
	struct stat		buf;
	t_list			*curr;
	char			*full_name;
	int				total;

	total = 0;
	curr = *head;
	while (curr)
	{
		full_name = ft_strjoin(curr->path, curr->name);
		if (lstat(full_name, &buf) == 0)
		{
			total += buf.st_blocks;
		}
		curr = curr->next;
		free(full_name);
	}
	ft_printf("total %d\n", total);
}
