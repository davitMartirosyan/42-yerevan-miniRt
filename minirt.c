/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:51:51 by dmartiro          #+#    #+#             */
/*   Updated: 2023/01/30 21:47:11 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main()
{
	t_render	render;
	
	render.mlx = mlx_init();
	t_vec		*sphere_vector = vec(3, 2, -32);
	t_sphere	*sphere = newsphere(sphere_vector, 12 / 2);
	t_vec		*origin_camera = vec(0, 0, 0);;
	t_vec		*direction = vec(0, 0, -1);
	t_cam		*cam = newcam(origin_camera, direction, 70);
	t_terrain	*scene = newscene(cam, sphere);
	scene->width = 800;
	scene->height = 600;
	render.mlx_win = mlx_new_window(&render.mlx, scene->width, scene->height , "Unreal Engine 6");
	raytracer(&render, scene);
	mlx_loop(&render.mlx);
	return (0);
}

//gcc  -lmlx -framework OpenGL -framework AppKit -I ./includes/ parser/*.c render/*.c vector/*.c utils/*.c minirt.c -o minrt