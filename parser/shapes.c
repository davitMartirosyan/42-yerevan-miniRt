/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:04:18 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/23 02:29:58 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	collect_shapes(t_table *table, t_scene *scene, char *filename)
{
	lights(&scene->light, filename);
}

void	lights(t_light **li, char *filename)
{
	int		fd;
    int     i;
    int     vec1;
	char	*line;
    char    **split;
    char    **div;

    split = NULL;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
    while (line)
    {
        split = ft_split(line, ' ');
        if (ft_strcmp(split[0], "L") == 0 || ft_strcmp(split[0], "l") == 0)
        {
            (*li) = (t_light *)ft_calloc(4, sizeof(t_light));
            i = 0;
            vec1 = 0;
            while (split[++i])
            {
                if (ft_strchr(split[i], ',') && vec1 == 0)
                {
                    div = ft_split(split[i], ',');
                    (*li)->cord = (t_vec3 *)ft_calloc(3, sizeof(t_vec3));
                    (*li)->cord->x = ft_atof(div[0]);
                    (*li)->cord->y = ft_atof(div[1]);
                    (*li)->cord->y = ft_atof(div[2]);
                    free_char_pp(&div);
                    vec1++;
                }
                else if (ft_strchr(split[i], ',') && vec1 == 1)
                {
                    div = ft_split(split[i], ',');
                    (*li)->rgb = (t_col *)ft_calloc(3, sizeof(t_col));
                    (*li)->rgb->r = ft_atof(div[0]);
                    (*li)->rgb->g = ft_atof(div[1]);
                    (*li)->rgb->b = ft_atof(div[2]);
                    free_char_pp(&div);
                    vec1++;
                }
                else
                    (*li)->brightness = ft_atof(split[i]);
            }
            li = &(*li)->next;
        }
        free_char_pp(&split);
        free(line);
        line = get_next_line(fd);
    }
}


//chogtagorcvox
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