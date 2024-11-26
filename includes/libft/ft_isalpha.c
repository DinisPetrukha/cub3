/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:13:49 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/12 21:12:29 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/*
int	main()
{
	printf("%d\n", ft_isalpha('q'));
	printf("%d\n", ft_isalpha('1'));
	printf("%d\n", isalpha('q'));
	printf("%d\n", isalpha('1'));
	return (0);
}*/
