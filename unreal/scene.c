/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:09:34 by dmartiro          #+#    #+#             */
/*   Updated: 2023/01/30 21:24:07 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_terrain	*newscene(t_cam *cam, t_sphere *sphere)
{
	t_terrain	*scene;

	scene = malloc(sizeof(t_terrain));
	if (!scene)
		failure(-1);
	scene->cameras = cam;
	scene->sphere = sphere;
	scene->width = 0;
	scene->height = 0;
	return (scene);
}