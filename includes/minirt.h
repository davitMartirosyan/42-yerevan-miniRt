/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:57:15 by dmartiro          #+#    #+#             */
/*   Updated: 2023/01/30 21:53:19 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <string.h>
# include "../mlx_mms/mlx.h"
# include <math.h>
# include "../libft/libft.h"
# include "structs.h"

/*Vector*/
t_vec		*vec(float x, float y, float z);
t_vec		*vecsubtract(t_vec *v1, t_vec *v2);
float		veclen(t_vec *vec);
void		vec_norm(t_vec *vec);
float		two_points(t_vec *v1, t_vec *v2);

/*utils*/
void		failure(int errcode);


/*Components*/
t_cam		*newcam(t_vec *origin, t_vec *direction, float fov);
t_terrain	*newscene(t_cam *cam, t_sphere *sphere);
t_sphere	*newsphere(t_vec *vec, float radius);

/*Tracer*/
void	raytracer(t_render *rend, t_terrain *scene);
#endif