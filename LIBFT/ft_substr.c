/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:40:35 by isneves-          #+#    #+#             */
/*   Updated: 2024/05/04 16:14:23 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (start >= i || len == 0)
		return (ft_strdup(""));
	if (start + len > i)
		len = i - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

/*int main()
{
    char str[] = "paralelepipedo";
    unsigned int start = 4; // Posição inicial da substring
    size_t len = 6;         // Comprimento da substring

    char *sub = ft_substr(str, start, len);
    if (sub != NULL)
    {
        printf("Substring: %s\n", sub);
        free(sub);
    }
    else
        printf("Erro: Substring inválida.\n");

    return 0;
}*/
