/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:51:51 by dmartiro          #+#    #+#             */
/*   Updated: 2023/01/30 23:26:38 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main()
{
	void		*mlx;
	void		*mlx_win;

	(void)mlx_win;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500 , "Unreal Engine 6");
	mlx_loop(mlx);
	return (0);
}

//gcc  -lmlx -framework OpenGL -framework AppKit -I ./includes/ parser/*.c render/*.c vector/*.c utils/*.c minirt.c -o minrt