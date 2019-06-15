#include "../includes/libls.h"

//добавляет элемент в конец списка
void	push(t_list **head, char *name)
{
	t_list	*curr;

	curr = *head;
	while (curr)
		curr = curr->next;
	curr = (t_list*)malloc(sizeof(t_list));
	curr->name = name;
	curr->next = NULL;
	curr->list_inside = NULL;
}

//показывает данные каждого элемента в списке
void	show(t_list **head)
{
	t_list	*curr;

	curr = *head;
	while (curr)
	{
		ft_printf("name = %s\n", curr->name);
		curr = curr->next;
	}
}

//создает лист new_name в листе name
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

//очистка листов с листами
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
