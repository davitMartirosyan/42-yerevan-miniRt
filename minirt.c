/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:51:51 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/01 16:35:40 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int ac, char *av[], char *envp[])
{
	void *mlx;
	void *mlx_win;

	(void)ac;
	(void)av;
	(void)envp;
	(void)mlx_win;
	(void)mlx;
	if(ac < 2)
		failure(-3);
	if (parser(av[1]) == -4)
		failure(-4);
	
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 600, 600, "Unreal Engine 5");
	// mlx_loop(mlx);
	return (0);
}