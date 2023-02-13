/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:32:43 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/13 19:01:08 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sp	*new_sp(t_vec3 *v, t_col *c, float r)
{
	t_sp	*sphere;

	sphere = malloc(sizeof(t_sp));
	sphere->cord = malloc(sizeof(t_vec3));
	if (!sphere || !sphere->cord)
		failure(-1);
	
	sphere->cord->x = v->x;
	sphere->cord->y = v->y;
	sphere->cord->z = v->z;

	sphere->color = create_rgb(c);
	sphere->radius = r;
	return (sphere);
}