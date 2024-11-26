/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:24:09 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/25 12:52:23 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// HOW CAN WE TEST THIS?
/*
void	ft_nodefree(void *node)
{
	free(node);
}*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	(*del)(lst->content);
	free(lst);
}
/*
int	main()
{
	char	ptr1[] = "ABCDEF";
	char	ptr2[] = "12345";
	t_list	*head;
	t_list	*tmp;

	tmp = ft_lstnew((void *)ptr1);
	ft_lstadd_front(&head, tmp);
	tmp = ft_lstnew((void *)ptr2);
	ft_lstadd_front(&head, tmp);
	printf("%s\n", head->content);
	printf("%s\n", head->next->content);
	ft_lstdelone(head->next, &ft_nodefree);
	printf("%s\n", head->content);
	printf("%s\n", head->next->content);
	return (0);
}*/
