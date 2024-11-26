/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:47:46 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/25 15:59:40 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// **lst endereco t_list
// *lst pointer t_list
// lst valor t_list?

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}
/*
int     main()
{
        char    a[] = "AA";
        char    b[] = "BBB";
        char    c[] = "CCCC";

        t_list  *head;
        t_list  *tmp;

        tmp = ft_lstnew((void *)a);
        ft_lstadd_back(&head, tmp);
        printf("1 %s\n", head->content);

        tmp = ft_lstnew((void *)b);
        ft_lstadd_back(&head, tmp);
        printf("2 %s\n", head->content);
        printf("3 %s\n", head->next->content);

        tmp = ft_lstnew((void *)c);
        ft_lstadd_back(&head, tmp);
        printf("4 %s\n", head->content);

        printf("5 %s\n", head->next->content);
        printf("6 %s\n", head->next->next->content);
        return (0);
	
}*/
