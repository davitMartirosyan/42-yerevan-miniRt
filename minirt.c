/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:51:51 by dmartiro          #+#    #+#             */
/*   Updated: 2023/01/30 19:31:18 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main()
{
	t_mlx_win	render;

	render.mlx = mlx_init();
	render.mlx_win = mlx_new_window(render.mlx, 500, 500, "MiniRT");
	mlx_loop(render.mlx);
	return (0);
}

int close_window(int keycode, t_mlx_win *render)
{
	mlx_destroy_window(render->mlx, render->mlx_win);
	return (0);
}

//gcc  -lmlx -framework OpenGL -framework AppKit -I ./includes/ parser/*.c render/*.c vector/*.c utils/*.c minirt.c -o minrt