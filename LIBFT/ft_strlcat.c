/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:37:06 by isneves-          #+#    #+#             */
/*   Updated: 2024/05/07 19:40:15 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	total_len;

	if ((!dst || !src) && !size)
		return (0);
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	total_len = dlen + slen;
	if (size <= dlen)
		return (slen + size);
	if (size > dlen + 1)
	{
		ft_strlcpy(dst + dlen, src, size - dlen);
	}
	return (total_len);
}

/*int main()
{
    char dest[20] = "abacate ";
    char src[20] = "e manga";
    size_t size = 25; 

    printf("%zu\n", ft_strlcat(dest, src, size));
    printf("Resultado: %s\n", dest); 

    return 0;
}*/
