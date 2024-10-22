/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:12:59 by isneves-          #+#    #+#             */
/*   Updated: 2024/05/13 21:17:04 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		++i;
	}
	return (dest);
}
/*
int main()
{
    char dest[10] = "abacate";
    char src[20] = "mangueira";
    size_t i = 3;

    printf("Antes da cópia\n");
    printf("dest: %s\n", dest);
    printf("src: %s\n", src);

    ft_memcpy(dest, src, i);
    
    printf("Depois da cópia\n");
    printf("dest: %s\n", dest);
}*/
