/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:40:56 by isneves-          #+#    #+#             */
/*   Updated: 2024/05/16 22:04:22 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = 0;
	while (s[len])
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

/*int main()
{
    const char *s = "Isabella Neves";
    char *duplicada = ft_strdup(s);
   
    if (duplicada != NULL)
	{
        printf("String duplicada: %s\n", duplicada);
        free(duplicada);
	}
    else
        printf("Erro ao duplicar a string.\n");

    return 0;
}*/
