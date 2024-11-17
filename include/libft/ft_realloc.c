/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:12:32 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/10/04 11:12:33 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//IF NO STR NEW IS CREATED AND CLEANED WITH NEW_SIZE

char	*ft_realloc(char *str, int len, int new_size)
{
	char	*ret;

	ret = NULL;
	if (!str)
	{
		ret = (char *)ft_calloc(new_size, sizeof(char));
		return (ret);
	}
	ret = (char *)ft_calloc(new_size + 1, sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, str, len + 1);
	if (*str)
		free(str);
	return (ret);
}
