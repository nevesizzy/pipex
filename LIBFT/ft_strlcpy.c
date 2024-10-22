/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:06:50 by isneves-          #+#    #+#             */
/*   Updated: 2024/05/04 16:07:06 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!size)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && (i < size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (ft_strlen(src));
}

/*int main()
{
    char dest[10] = "manga";
    char src[10] = "abacates";
    size_t size = 25;

    printf("Antes:%s\n", dest);
    printf("%zu\n", ft_strlcpy(dest, src, size)); 
    printf("Depois:%s\n", dest);
}*/
