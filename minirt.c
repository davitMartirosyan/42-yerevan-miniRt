/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:51:51 by dmartiro          #+#    #+#             */
/*   Updated: 2023/01/28 07:14:10 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main()
{
	t_mlx_win render;

	render.mlx = mlx_init();
	render.mlx_win = mlx_new_window(render.mlx, 500, 500, "MiniRT");
	mlx_hook(render.mlx_win, 2, 1L<<0, close_window, &render);
	mlx_loop(render.mlx);
	return (0);
}

int close_window(int keycode, t_mlx_win *render)
{
	mlx_destroy_window(render->mlx, render->mlx_win);
	return (0);
}

//gcc  -lmlx -framework OpenGL -framework AppKit -I ./includes/ parser/*.c render/*.c minirt.c -o minrt