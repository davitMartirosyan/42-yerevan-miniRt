/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:51:51 by dmartiro          #+#    #+#             */
/*   Updated: 2023/03/03 19:34:31 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int ac, char **av)
{
	int		parse_compose;
	t_scene	*scene;
	t_table	*table;
	
	scene = NULL;
	table = NULL;
	if (ac != 4)
		failure(-3);
	init(&table, &scene);
	if(parser(table, scene, av[1]) > 0)
	{
		table->w = ft_atof(av[2]);
		table->h = ft_atof(av[3]);
		render(table, scene);
	}
	else
		failure(table->def);
	return (0);
}

void	init(t_table **table, t_scene **scene)
{
	*table = ft_calloc(2, sizeof(t_table));
	*scene = ft_calloc(7, sizeof(t_scene));
	if (!*table || !*scene)
		failure(-1);
	(*scene)->ambient_light = ft_calloc(3, sizeof(t_ambient));
	(*scene)->camera = ft_calloc(4, sizeof(t_cam));
	if (!(*scene)->ambient_light || !(*scene)->camera)
		failure(-1);
}

