/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:14:23 by isneves-          #+#    #+#             */
/*   Updated: 2024/05/13 21:07:38 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char			*p;
	size_t					i;

	i = 0;
	p = s;
	while (i < n)
	{
		p[i] = 0;
		++i;
	}
}

/*int main()
{
    char str[20] = "isabella neves"; 
    size_t n = 5;

    printf("Antes: %s\n", str);
    ft_bzero(str, n);
	str[n] = '\0';
    printf("Depois: %s\n", str);

    return 0;
    
	char str2[20] = "isabella neves"; 

    printf("Antes 2: %s\n", str2);
    ft_bzero(str, sizeof(str2));
    printf("Depois 2: %s\n", str2);

    return 0;
}*/
