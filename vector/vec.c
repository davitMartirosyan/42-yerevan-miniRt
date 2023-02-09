/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:51:05 by dmartiro          #+#    #+#             */
/*   Updated: 2023/01/30 20:00:57 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	*vec_(float x, float y, float z)
{
	t_vec	*vector;

	vector = malloc(sizeof(t_vec));
	if(!vector)
		failure(-1);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

void	veclen(t_vec *vec)
{
	vec->l = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
}

void	vecnorm(t_vec *vec)
{
	float vec_tmp;

	vec_tmp = 1 / vec->l;
	vec->x *= vec_tmp;
	vec->y *= vec_tmp;
	vec->z *= vec_tmp;
	vec->x = ceil(vec->x);
	vec->y = ceil(vec->y);
	vec->z = ceil(vec->z);
}

float	dot(t_vec *v1, t_vec *v2)
{
	float	dot_p;
	dot_p = (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
	return (dot_p);
}
