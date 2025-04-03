/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:39:18 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/03 18:01:16 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! ft_safe_malloc:
#include "so_long.h"

//? Zero out a block of memory.
static void	ft_bzero(void *s, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (len--)
		*tmp++ = 0;
}

//? Free all allocated memory in the memory tracking list and exit.
static void	free_list(t_mem_node **list, int exit_status)
{
	t_mem_node	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->address);
		free(*list);
		*list = tmp;
	}
	exit(exit_status);
}

//? Add a new memory block to the memory tracking list.
static void	lst_add_back_malloc(t_mem_node **lst, void *value)
{
	t_mem_node	*last;
	t_mem_node	*tmp;

	if (!lst || !value)
		return ;
	tmp = malloc(sizeof(t_mem_node));
	if (!tmp)
		free_list(lst, -1);
	tmp->address = value;
	tmp->next = NULL;
	if (!*lst)
	{
		*lst = tmp;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = tmp;
}

//? Free a specific memory block and update the tracking list
static void	free_specific_node(t_mem_node **lst, void *to_delete)
{
	t_mem_node	*current;
	t_mem_node	*prev;

	if (!lst || !*lst || !to_delete)
		return ;
	current = *lst;
	prev = NULL;
	while (current)
	{
		if (current->address == to_delete)
		{
			free(current->address);
			if (prev)
				prev->next = current->next;
			else
				*lst = current->next;
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

//? Allocate memory, track it, and handle failures safely.
void	*ft_safe_malloc(size_t size, int key, int exit_status, void *to_delete)
{
	static t_mem_node	*mem_node;
	void				*ptr;

	ptr = NULL;
	if (key == ALLOCATE)
	{
		ptr = malloc(size);
		if (!ptr)
			free_list(&mem_node, -1);
		lst_add_back_malloc(&mem_node, ptr);
		ft_bzero(ptr, size);
	}
	else if (key == FREE_ALL)
		free_list(&mem_node, exit_status);
	else if (key == FREE_ONE)
		free_specific_node(&mem_node, to_delete);
	return (ptr);
}
