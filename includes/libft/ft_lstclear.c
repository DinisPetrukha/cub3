/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:53:33 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/25 15:57:02 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	test(void *node)
{
	printf("REMOVED %s\n", (char *)node);
	free(node);
}

void	lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = 0;
}
/*
int	main()
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

	printf("7 %p\n", head);
	printf("7 %p\n", head->next);
	ft_lstclear(&head, &test);
//        printf("7 %s\n", head->content);
        return (0);
}*/
