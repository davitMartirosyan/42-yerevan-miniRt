/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:04:18 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/28 00:10:05 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	collect_shapes(t_table *table, t_scene *scene, char *filename)
{
    static int  lscp[4] = {0};
    shape_counter(lscp, filename);
    light(lscp[0], scene, filename);
    plane(lscp[1], scene, filename);
	sphere(lscp[2], scene, filename);
	
}

void	shape_counter(int *lpsc, char *filename)
{
	int fd;
	char *line;
	char	**split;
	
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, ' ');
		if (ft_strcmp(split[0], "L") == 0 || ft_strcmp(split[0], "l") == 0)
			lpsc[0]++;
		else if (ft_strcmp(split[0], "pl") == 0)
			lpsc[1]++;
		else if (ft_strcmp(split[0], "sp") == 0)
			lpsc[2]++;
		else if (ft_strcmp(split[0], "cy") == 0)
			lpsc[3]++;
		free_char_pp(&split);
        free(line);
		line = get_next_line(fd);
	}
	close(fd);
}