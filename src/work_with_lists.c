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

void			push(t_list **head_ref, char *new_data)
{
	t_list *new_node;

	new_node = (t_list*)malloc(sizeof(t_list));
	new_node->name = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void	show_list(t_list **head)
{
	t_list	*curr;

	curr = *head;
	while (curr)
	{
		write(1, curr->name, ft_strlen(curr->name));
		write(1, "\n", 1);
		curr = curr->next;
	}
}

void	create_list_inside_list(t_list **head, char *name, char *new_name)
{
	t_list *curr;

	curr = *head;
	while (curr)
	{
		if (!ft_strcmp(curr->name, name))
			break ;
		curr = curr->next;
	}
	if (curr == NULL)
	{
		write(2, "error while creating list inside list\n", 38);
		exit(2);
	}
	while (curr->list_inside)
		curr->list_inside = curr->list_inside->next;
	curr->list_inside = (t_list*)malloc(sizeof(t_list));
	curr->list_inside->name = new_name;
	curr->list_inside->next = NULL;
}

void	clear_all(t_list **head)
{
	t_list *curr;
	t_list *curr_inside;

	while ((*head))
	{
		curr = (*head);
		while (curr->list_inside)
		{
			curr_inside = curr->list_inside;
			curr->list_inside = curr->list_inside->next;
			free(curr_inside);
		}
		(*head) = (*head)->next;
		free(curr);
	}
}
