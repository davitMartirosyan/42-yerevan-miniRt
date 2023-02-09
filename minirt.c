/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:51:51 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/01 16:35:40 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int ac, char *av[], char *envp[])
{
	t_vec	*vec;
	float	x;
	float	y;
	float	z;

	x = 5;
	y = 8;
	z = 6;

	vec = vec_(x, y, z);
	veclen(vec);
	vecnorm(vec);
	printf("%f : %f : %f\n", vec->x, vec->y, vec->z);

	return (0);
}