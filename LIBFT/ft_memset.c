/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:51:55 by isneves-          #+#    #+#             */
/*   Updated: 2024/05/13 21:03:21 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*src;
	size_t				i;

	src = s;
	i = 0;
	while (i < n)
	{
		src[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int main()
{
	char str[20] = "isabella"; 
    size_t n = 3;
   
    printf("Antes: %s\n", str);
    ft_memset(str, 'b', n);
    printf("Depois: %s\n", str);

    return 0;
}*/
