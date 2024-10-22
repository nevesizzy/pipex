/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:44:28 by isneves-          #+#    #+#             */
/*   Updated: 2024/05/04 16:52:40 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n && *d == *s)
	{
		++d;
		++s;
		--n;
	}
	if (n)
		return (*d - *s);
	else
		return (0);
}

/*int main() 
{
    char str1[] = "isabella";
    char str2[] = "isabell";
    size_t n = 8;

    int result = ft_memcmp(str1, str2, n);

    if (result < 0) 
        printf("%i\n", result);
	else if (result > 0) 
        printf("%i\n", result);
	else 
        printf("%i\n", result);

    return 0;
}*/
