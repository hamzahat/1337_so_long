/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:39:18 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/03/28 20:46:06 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_bzero(void *s, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (len--)
		*tmp++ = 0;
}

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

//? it allocate and check for failing and free safely
void	*ft_safe_malloc(size_t size, int key, int exit_status)
{
	static t_mem_node	*mem_node;
	void				*ptr;

	ptr = NULL;
	if (key == 1)
	{
		ptr = malloc(size);
		if (!ptr)
			free_list(&mem_node, -1);
		lst_add_back_malloc(&mem_node, ptr);
		ft_bzero(ptr, size);
	}
	if (key == 0)
		free_list(&mem_node, exit_status);
	return (ptr);
}
