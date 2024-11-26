/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:02:49 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/25 15:56:27 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
/*
int	main()
{
	char	a[] = "CC";
	char	b[] = "BBB";
	char	c[] = "AAAA";
	t_list  *head;
	t_list	*tmp;

	tmp = ft_lstnew((void *)a);
	ft_lstadd_front(&head, tmp);
	tmp = ft_lstnew((void *)b);
	ft_lstadd_front(&head, tmp);
	tmp = ft_lstnew((void *)c);
	ft_lstadd_front(&head, tmp);
	printf("%s\n", head->content);
	printf("%s\n", head->next->content);
	printf("%s\n", head->next->next->content);
	printf("%d\n", ft_lstsize(head));
	return (0);
}*/
