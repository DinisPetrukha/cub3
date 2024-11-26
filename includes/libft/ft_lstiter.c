/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:43:59 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/25 13:35:49 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	test(void *node)
{
	char	s[] = "PAULO";

	ft_memcpy(node, s, 6);
}*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*
int     main()
{
        char    ptr1[] = "ABCDEF";
        char    ptr2[] = "12345";
        char    ptr3[] = "UMUMU";
        t_list  *head;
        t_list  *tmp;

        tmp = ft_lstnew((void *)ptr1);
        ft_lstadd_front(&head, tmp);
        tmp = ft_lstnew((void *)ptr2);
        ft_lstadd_front(&head, tmp);
	tmp = ft_lstnew((void *)ptr3);
        ft_lstadd_front(&head, tmp);
        printf("%s\n", head->content);
        printf("%s\n", head->next->content);
        printf("%s\n", head->next->next->content);
        ft_lstiter(head, &test);
        printf("%s\n", head->content);
        printf("%s\n", head->next->content);
        printf("%s\n", head->next->next->content);
        return (0);
}*/
