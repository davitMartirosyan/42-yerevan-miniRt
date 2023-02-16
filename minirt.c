/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:51:51 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/16 07:29:32 by dmartiro         ###   ########.fr       */
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
	
	if (ac < 2 || ac > 2)
		failure(-3);
	// table = init_table();
	init(&table, &scene);
	parse_compose = parser(table, scene, av[1]);
	printf("%f\n", scene->ambient_light->brightness);

	if(parse_compose > 0)
		render(scene);
	else
		failure(parse_compose);
	
	return (0);
}

void	init(t_table **table, t_scene **scene)
{
	*table = ft_calloc(2, sizeof(t_table));
	*scene = ft_calloc(6, sizeof(t_scene));
	if (!*table || !*scene)
		failure(-1);
	(*scene)->ambient_light = ft_calloc(3, sizeof(t_ambient));
	(*scene)->camera = ft_calloc(4, sizeof(t_cam));
	(*scene)->light = ft_calloc(5, sizeof(t_light));
	(*scene)->plane = ft_calloc(6, sizeof(t_pl));
	(*scene)->spheres = ft_calloc(6, sizeof(t_sp));
	(*scene)->cylinders = ft_calloc(8, sizeof(t_cy));
	if (!(*scene)->ambient_light || !(*scene)->camera || !(*scene)->cylinders
		|| !(*scene)->light || !(*scene)->plane || !(*scene)->spheres)
		failure(-1);
}

