/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:09:19 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/25 15:51:30 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	*ftest(void *node)
{
	return ((void *)"PAULO");
}

void	deltest(void *node)
{
	printf("REMOVE\n");
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;

	newlst = NULL;
	while (lst != NULL)
	{
		tmp = (malloc(sizeof(t_list)));
		if (tmp == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		tmp->content = (*f)(lst->content);
		tmp->next = NULL;
		ft_lstadd_back(&newlst, tmp);
		lst = lst->next;
	}
	return (newlst);
}
/*
int     main()
{
        char    ptr1[] = "ABCDE";
        char    ptr2[] = "12345";
        char    ptr3[] = "UMUMU";
	t_list	*new;
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
        new = ft_lstmap(head, &ftest, &free);
        printf("%s\n", head->content);
        printf("%s\n", head->next->content);
        printf("%s\n", head->next->next->content);
        printf("2: %s\n", new->content);
        printf("2: %s\n", new->next->content);
        printf("2: %s\n", new->next->next->content);
        return (0);
}*/
