/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:33:06 by dmartiro          #+#    #+#             */
/*   Updated: 2023/01/30 21:35:33 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*newsphere(t_vec *vec, float radius)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if(!sphere)
		failure(-1);
	sphere->xyz = vec;
	sphere->radius = radius;
	return (sphere);
}