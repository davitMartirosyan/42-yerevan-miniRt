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

t_vec	*vec(float x, float y, float z)
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

t_vec	*vecsubtract(t_vec *v1, t_vec *v2)
{
	t_vec	*vecsubtractor;

	vecsubtractor = vec(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
	return (vecsubtractor);
}


float	veclen(t_vec *vec)
{
	float	vlen;

	vlen = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
	return (vlen);
}

void	vec_norm(t_vec *vec)
{
	float	vlen;

	vlen = veclen(vec);
	vec->x /= vlen;
	vec->y /= vlen;
	vec->z /= vlen;
}

float	two_points(t_vec *v1, t_vec *v2)
{
	float	points;

	points = ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
	return (points);
}