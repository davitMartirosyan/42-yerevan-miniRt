/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:51:51 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/13 20:07:38 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main()
{
	t_sp	*sp;
	t_vec3	v;
	t_col	rgb;
	float	r;

	r = 12.6;
	v.x = 0.0;
	v.y = 0.0;
	v.z = 20.6;
	
	rgb.r = 255;
	rgb.g = 0;
	rgb.b = 0;

	sp = new_sp(&v, &rgb, r);

	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "unreal engine");
	int i, j;
	i = 0;
	while (i <= 500)
	{
		j = 0;
		while (j++ < 500)
			mlx_pixel_put(mlx, mlx_win, j, i, sp->color);
		i++;
	}
	mlx_loop(mlx);
	return (0);
}


//  0.0, 0.0, 20.6    12.6      10,0,255