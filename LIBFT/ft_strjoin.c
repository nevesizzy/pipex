/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:46:03 by isneves-          #+#    #+#             */
/*   Updated: 2024/05/16 22:26:17 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, len1 + 1);
	ft_strlcat(newstr, s2, len1 + len2 + 1);
	return (newstr);
}

/*int main()
{
    char *str1 = "";
    char *str2 = NULL;

    char *join = ft_strjoin(str1, str2);

    if (join != NULL)
	{
        printf("Resultado: %s\n", join);
        free(join);
    }
    else
        printf("Resultado: NULL\n");

    return 0;
}*/
