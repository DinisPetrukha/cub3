/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:55:21 by sephilip          #+#    #+#             */
/*   Updated: 2024/09/29 13:18:38 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	if (lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
/*
int	main()
{
	t_list *hey;
	t_list *sec;
	t_list *third;

	hey = ft_lstnew((void *)"a pois e ");
	sec = ft_lstnew((void *)"bebe");
	third = ft_lstnew((void *)"!!!");

	ft_lstadd_front(&hey, sec);
	ft_lstadd_front(&hey, third);
	//printf"%s\n", hey->content);
	//printf"%s\n", hey->next->content);
	//printf"%s\n", hey->next->next->content);
	return (0);
}*/
