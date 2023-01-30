/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:57:15 by dmartiro          #+#    #+#             */
/*   Updated: 2023/01/30 19:33:57 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <string.h>
# include "../mlx_mms/mlx.h"
# include <math.h>
# include "definitions.h"
# include "../libft/libft.h"
# include "structs.h"


//MLX windows
int close_window(int keycode, t_mlx_win *render);


/*Vector*/
t_vec	*vec(float x, float y, float z);
t_vec	*vecsubtract(t_vec *v1, t_vec *v2);
float	veclen(t_vec *vec);
void	vec_norm(t_vec *vec);
float	two_points(t_vec *v1, t_vec *v2);


/*utils*/
void	failure(int errcode);
#endif