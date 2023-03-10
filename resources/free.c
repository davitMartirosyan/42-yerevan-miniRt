/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 07:13:52 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/16 07:18:17 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_char_pp(char ***pp)
{
	int	i;

	i = -1;
	if (!(*pp) && !*(*pp))
		return ;
	while ((*pp)[++i])
		free((*pp)[i]);
	free((*pp));
	(*pp) = NULL;
}