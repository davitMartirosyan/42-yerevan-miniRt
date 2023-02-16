/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:18:15 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/17 00:44:44 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render(t_table *table, t_scene *scene)
{
	printf("CAMERA CORDINATES : \n");
	printf("XYZ -> %f : %f : %f\n", scene->camera->cord->x, scene->camera->cord->y, scene->camera->cord->z);
	printf("NORMAL VECTOR -> %f : %f : %f\n", scene->camera->normal->x, scene->camera->normal->y, scene->camera->normal->z);
	printf("FILD OF VIEW: %d\n", scene->camera->hfov);
}