/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:35:58 by isneves-          #+#    #+#             */
/*   Updated: 2024/05/04 15:37:51 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;
	size_t	i;

	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

/*int main()
{
    int *arr;
    size_t nmemb = 5;
    size_t size = sizeof(int);

    arr = ft_calloc(nmemb, size);

    if (arr != NULL)
    {
        printf("Memória alocada com sucesso!\n");
        free(arr);
    }
    else
        printf("Erro ao alocar memória.\n");

    return 0;
}*/
