/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:51:51 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/15 20:17:50 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int ac, char **av)
{
	t_scene	*scene;
	int		parse_compose;
	
	if (ac < 2 || ac > 2)
		failure(-3);
	parse_compose = parser(scene, av[1])
	if(parse_compose > 0)
		render(scene);
	else
		failure(parse_compose);
	return (0);
}


