/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyvchyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 11:50:36 by anyvchyk          #+#    #+#             */
/*   Updated: 2019/06/27 11:50:38 by anyvchyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libls.h"

static t_list		*merge_sorted_lists_by_time(t_list *a, t_list *b)
{
	t_list			*result;
	struct stat		st[2];
	char			*name[2];

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	name[0] = ft_strjoin(a->path, a->name);
	name[1] = ft_strjoin(b->path, b->name);
	lstat(name[0], &st[0]);
	lstat(name[1], &st[1]);
	if (st[0].st_mtime > st[1].st_mtime)
	{
		result = a;
		result->next = merge_sorted_lists_by_time(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge_sorted_lists_by_time(a, b->next);
	}
	free(name[0]);
	free(name[1]);
	return (result);
}

static t_list		*merge_sorted_lists(t_list *a, t_list *b)
{
	t_list *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->name, b->name) < 0)
	{
		result = a;
		result->next = merge_sorted_lists(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge_sorted_lists(a, b->next);
	}
	return (result);
}

static void			dividing(t_list *source, t_list **front_ref,
		t_list **back_ref)
{
	t_list	*fast;
	t_list	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = NULL;
}

void				merge_sort(t_list **head_ref, const int how_to_sort)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *head_ref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	dividing(head, &a, &b);
	merge_sort(&a, how_to_sort);
	merge_sort(&b, how_to_sort);
	*head_ref = (how_to_sort == 1) ?
			merge_sorted_lists(a, b) :
			merge_sorted_lists_by_time(a, b);
}
