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

static t_list		*merge_sorted_lists(t_list *a, t_list *b);
static void			dividing(t_list *source, t_list **frontRef, t_list **backRef);

void				merge_sort(t_list **headRef)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *headRef;
	if ((head == NULL) || (head->next == NULL))
		return;
	dividing(head, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*headRef = merge_sorted_lists(a, b);
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

static void			dividing(t_list *source, t_list **frontRef, t_list **backRef)
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
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}
