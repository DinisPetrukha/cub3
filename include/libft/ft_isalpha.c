/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:13:49 by sephilip          #+#    #+#             */
/*   Updated: 2024/09/29 13:18:38 by dpetrukh         ###   ########.fr       */
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
	//printf"%d\n", ft_isalpha('q'));
	//printf"%d\n", ft_isalpha('1'));
	//printf"%d\n", isalpha('q'));
	//printf"%d\n", isalpha('1'));
	return (0);
}*/
