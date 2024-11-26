/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:17:48 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/24 14:24:41 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int     main()
{
        char    a[] = "CC";
        char    b[] = "BBB";
        char    c[] = "AAAA";
        t_list  *head;
        t_list  *tmp;

        tmp = ft_lstnew((void *)a);
        ft_lstadd_front(&head, tmp);
        tmp = ft_lstnew((void *)b);
        ft_lstadd_front(&head, tmp);
        tmp = ft_lstnew((void *)c);
        ft_lstadd_front(&head, tmp);
        printf("%s\n", head->content);
        printf("%s\n", head->next->content);
        printf("%s\n", head->next->next->content);
        printf("%s\n", (ft_lstlast(head))->content);
        return (0);
}*/
