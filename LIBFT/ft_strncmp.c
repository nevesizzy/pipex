/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:43:08 by isneves-          #+#    #+#             */
/*   Updated: 2024/05/07 19:48:04 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	str1;
	unsigned char	str2;
	size_t			i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		str1 = (unsigned char)s1[i];
		str2 = (unsigned char)s2[i];
		if (str1 < str2)
			return (-1);
		else if (str1 > str2)
			return (1);
		i++;
	}
	if (i < n && s1[i] != '\0')
		return (1);
	else if (i < n && s2[i] != '\0')
		return (-1);
	return (0);
}

/*int main()
{
    const char *s1 = "abc";
    const char *s2 = "abcc";
    size_t n = 4;

    int result = ft_strncmp(s1, s2, n);

    printf("Resultado da comparação: %d\n", result);

    return 0;
}*/
