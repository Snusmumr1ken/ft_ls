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

void	push(t_list **head_ref, char *new_data)
{
	t_list *new_node;

	new_node = (t_list*)malloc(sizeof(t_list));

	new_node->name = ft_strdup(new_data);
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void	show_list(t_list **head)
{
	t_list	*curr;

	curr = *head;
	while (curr)
	{
		ft_printf(GREEN "\t%s\n" WHITE, curr->name);
		curr = curr->next;
	}
}

void	delete_list(t_list **head)
{
	t_list		*curr;
	t_list		*next;

	curr = *head;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr->name);
		free(curr);
		curr = next;
	}
	*head = NULL;
}

void	reverse_list(t_list **head_ref)
{
	t_list *first;
	t_list *rest;

	if (*head_ref == NULL)
		return ;
	first = *head_ref;
	rest  = first->next;
	if (rest == NULL)
		return;
	reverse_list(&rest);
	first->next->next = first;
	first->next = NULL;
	*head_ref = rest;
}
