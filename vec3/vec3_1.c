/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:04:58 by dmartiro          #+#    #+#             */
/*   Updated: 2023/03/03 18:17:57 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	*vecsum(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3	*vec3sum;

	vec3sum = (t_vec3 *)ft_calloc(3, sizeof(t_vec3));
	vec3sum->x = (v1->x + v2->x);
	vec3sum->y = (v1->y + v2->y);
	vec3sum->z = (v1->z + v2->z);
	return (vec3sum);

}

t_vec3	*vecmul(t_vec3 *v1, float p)
{
	t_vec3	*vec3mul;

	vec3mul = (t_vec3 *)ft_calloc(3, sizeof(t_vec3));
	vec3mul->x = (v1->x * p);
	vec3mul->y = (v1->y * p);
	vec3mul->z = (v1->z * p);
	return (vec3mul);
}

t_vec3	*vecsub(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3	*vec3sub;
	
	vec3sub = (t_vec3 *)ft_calloc(3, sizeof(t_vec3));
	vec3sub->x = (v1->x - v2->x);
	vec3sub->y = (v1->y - v2->y);
	vec3sub->z = (v1->z - v2->z);
	return (vec3sub);
}

t_vec3	*vecnorm(t_vec3 *v1)
{
	t_vec3	*vec3norm;

	vec3norm = (t_vec3 *)ft_calloc(3, sizeof(t_vec3));
	vec3norm->
}

float	veclen(t_vec3 *v1)
{
	float	len;
	
	len = sqrt(pow(v1->x, 2) + pow(v1->y, 2) + pow(v1->z, 2));
	return (len);
}
