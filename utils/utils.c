/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:17:07 by dmartiro          #+#    #+#             */
/*   Updated: 2023/01/31 21:49:55 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	failure(int errcode)
{
	if (errcode == -1)
		printf("Can't allocate memmory!\n");
	else if (errcode == -2)
		printf("File not found\n");
	else if (errcode == -3)
		printf("Argument Error!\n");
	else if (errcode == -4)
		printf("File Not Found!\n");
	else if (errcode == -5)
		printf("Error Occured: Components Was Repeats in File!\n");
	exit(errcode);
}