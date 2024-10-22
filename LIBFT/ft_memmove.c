/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:16:06 by isneves-          #+#    #+#             */
/*   Updated: 2024/04/28 15:13:21 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!dest && !src)
		return (dest);
	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	while (n--)
		d[n] = s[n];
	return (dest);
}

/*int main()
{
	char str1[20] = "eu te amo bobinho";
	char str2[20];
	
	printf("Antes: str1 = \"%s\", str2 = \"%s\"\n", str1, str2);
	ft_memmove(str2, str1, 9);
	printf("Depois: str1 = \"%s\", str2 = \"%s\"\n", str1, str2);

    return 0;
}*/
