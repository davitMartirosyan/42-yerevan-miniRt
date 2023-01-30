/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cameramesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:26:48 by dmartiro          #+#    #+#             */
/*   Updated: 2023/01/30 20:57:09 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam	*newcam(t_vec *origin, t_vec *direction, float fov)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		failure(-1);
	cam->origin = origin;
	cam->direction = direction;
	cam->hfov = fov;
	return (cam);
}