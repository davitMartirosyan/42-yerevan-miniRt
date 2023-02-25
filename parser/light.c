/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:45:31 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/25 13:32:41 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
static void collect(t_light *l, char **split);

void    light(int led, t_scene *scene, char *filename)
{
    t_spin  spin;
    int i;
    
    i = -1;
    spin.fd = open(filename, O_RDONLY);
    scene->light = (t_light *)ft_calloc(3, (led * sizeof(t_light)));
    spin.line = get_next_line(spin.fd);
    while (spin.line)
    {
        spin.split = ft_split(spin.line, ' ');
        if (ft_strcmp(spin.split[0], "L") == 0 || ft_strcmp(spin.split[0], "l") == 0)
            collect(&scene->light[++i], spin.split);
        free_char_pp(&spin.split);
        free(spin.line);
        spin.line = get_next_line(spin.fd);
    }
}

static void collect(t_light *l, char **split)
{
    int     i;
    char    **div;
    int     xyz;
    
    i = 0;
    xyz = 0;
    while (split[++i])
    {
        if (ft_strchr(split[i], ',') && xyz == 0)
        {
            div = ft_split(split[i], ',');
            l->cord = (t_vec3 *)ft_calloc(3, sizeof(t_vec3));
            l->cord->x = ft_atof(div[0]);
            l->cord->y = ft_atof(div[1]);
            l->cord->z = ft_atof(div[2]);
            free_char_pp(&div);
            xyz++;
        }
        else if (ft_strchr(split[i], ',') && xyz == 1)
        {
             div = ft_split(split[i], ',');
             l->rgb = (t_col *)ft_calloc(3, sizeof(t_col));
             l->rgb->r = ft_atoi(div[0]);
             l->rgb->g = ft_atoi(div[1]);
             l->rgb->b = ft_atoi(div[2]);
             free_char_pp(&div);
             xyz++;
        }
        else
            l->brightness = ft_atof(split[i]);
    }
}