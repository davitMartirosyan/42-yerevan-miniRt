/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 05:09:15 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/23 02:04:39 by dmartiro         ###   ########.fr       */
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
		free(line);
		line = get_next_line(fd);
	}
	if (table->ambient_count > 1 || table->camera_count > 1)
	{
		table->def = -5;
		return (-5);
	}
	close(fd);
	collect_shapes(table, scene, f);
    return (1);
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
	else if (ft_strcmp(split[0], "C") == 0 || ft_strcmp(split[0], "c") == 0)
		camera(table, scene->camera, split);
	free_char_pp(&split);
}

void	camera(t_table *table, t_cam *camera, char **split)
{
	int	i;
	char	**div;
	int		xyz;
	int		vecnorm;
	
	i = 0;
	xyz = 0;
	vecnorm = 0;
	table->camera_count++;
	while (split[++i])
	{
		if (ft_strchr(split[i], ',') && xyz == 0)
		{
			div = ft_split(split[i], ',');
			camera->cord = (t_vec3 *)ft_calloc(3, sizeof(t_vec3));
			camera->cord->x = ft_atof(div[0]);
			camera->cord->y = ft_atof(div[1]);
			camera->cord->z = ft_atof(div[2]);
			free_char_pp(&div);
			xyz++;
		}
		else if (ft_strchr(split[i], ',') && vecnorm == 0)
		{
			div = ft_split(split[i], ',');
			camera->normal = (t_vec3 *)ft_calloc(3, sizeof(t_vec3));
			camera->normal->x = ft_atof(div[0]);
			camera->normal->y = ft_atof(div[1]);
			camera->normal->z = ft_atof(div[2]);
			free_char_pp(&div);
			vecnorm++;
		}
		else
			camera->hfov = ft_atoi(split[i]);
	}
}

void	ambient(t_table *table, t_ambient *a_light, char **split)
{
	int	i;
	char	**div;

	div = NULL;
	i = 0;
	table->ambient_count++;
	while (split[++i])
	{
		if (ft_strchr(split[i], ','))
		{
			
			div = ft_split(split[i], ',');
			a_light->rgb = (t_col *)ft_calloc(3, sizeof(t_col));
			a_light->rgb->r = ft_atoi(div[0]);
			a_light->rgb->g = ft_atoi(div[1]);
			a_light->rgb->b = ft_atoi(div[2]);
			free_char_pp(&div);
		}
		else
			a_light->brightness = ft_atof(split[i]);
	}
}