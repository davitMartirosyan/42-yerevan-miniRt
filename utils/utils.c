/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:17:07 by dmartiro          #+#    #+#             */
/*   Updated: 2023/01/30 19:19:24 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	failure(int errcode)
{
	if (errcode == -1)
		write(2, "Can't allocate memmory\n", 23);
	else if (errcode == -2)
		write(2, "File not found\n", 15);
	exit(-1);
}