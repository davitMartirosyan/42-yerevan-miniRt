/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 05:09:15 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/16 07:16:32 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int parser(t_table *table, t_scene *scene, char *f)
{
    char	*line;
	int		fd;
	
	fd = open(f, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		collect_objects(table, scene, line);
		line = get_next_line(fd);
	}
	if (table->ambient_count > 1 || table->camera_count > 1)
		failure(-5);
    return (0);
}

void	collect_objects(t_table *table, t_scene *scene, char *line)
{
	char	**split;
	int		i;
	int		c;
	
	i = 0;
	c = 0;
	split = ft_split(line, ' ');
	if (ft_strcmp(split[0], "A") == 0)
		ambient(table, scene->ambient_light, split);
}

void	ambient(t_table *table, t_ambient *a_light, char **split)
{
	int	i;
	char	**div;

	div = NULL;
	i = 0;
	while (split[++i])
	{
		if (ft_strchr(split[i], ','))
		{
			div = ft_split(split[i], ',');
			a_light->rgb = (t_col *)malloc(sizeof(t_col));
			a_light->rgb->r = ft_atoi(div[0]);
			a_light->rgb->g = ft_atoi(div[1]);
			a_light->rgb->b = ft_atoi(div[2]);
			free_char_pp(&div);
		}
		else
			a_light->brightness = ft_atoi(split[i]);
	}
}