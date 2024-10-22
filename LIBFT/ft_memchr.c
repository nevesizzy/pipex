/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:43:40 by isneves-          #+#    #+#             */
/*   Updated: 2024/05/04 12:35:58 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	i = 0;
	ptr = s;
	while (i < n)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
		i++;
	}
	return (NULL);
}

/*int main()
{
    char str[20] = "isabella";
    size_t n = 3;
    char c = 'a'; 
    char *result;

    result = ft_memchr(str, c, n);
    
    if (result != NULL) 
    	printf("'%c' encontrado na posição: %ld\n", c, result - str);
	else 
        printf("'%c' não encontrado na string.\n", c, n);
    return 0;
}*/
