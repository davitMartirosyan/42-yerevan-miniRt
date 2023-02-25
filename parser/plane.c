/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:31:02 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/25 13:43:53 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void collect(t_pl *pl, char **split);

void    plane(int pl, t_scene *scene, char *filename)
{
    t_spin  spin;
    int i;
    
    i = -1;
    spin.fd = open(filename, O_RDONLY);
    scene->plane = (t_pl *)ft_calloc(4, (pl * sizeof(t_pl)));
    spin.line = get_next_line(spin.fd);
    while (spin.line)
    {
         spin.split = ft_split(spin.line, ' ');
        if (ft_strcmp(spin.split[0], "pl") == 0)
            collect(&scene->plane[++i], spin.split);
        free_char_pp(&spin.split);
        free(spin.line);
        spin.line = get_next_line(spin.fd);
    }
}

static void collect(t_pl *pl, char **split)
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
            pl->cord = (t_vec3 *)ft_calloc(3, sizeof(t_vec3));
            pl->cord->x = ft_atof(div[0]);
            pl->cord->y = ft_atof(div[1]);
            pl->cord->z = ft_atof(div[2]);
            xyz++;
            free_char_pp(&div);
       }
       else if (ft_strchr(split[i], ',') && xyz == 1)
       {
            div = ft_split(split[i], ',');
            pl->normal = (t_vec3 *)ft_calloc(3, sizeof(t_vec3));
            pl->normal->x = ft_atof(div[0]);
            pl->normal->y = ft_atof(div[1]);
            pl->normal->z = ft_atof(div[2]);
            xyz++;
            free_char_pp(&div);
       }
       else if (ft_strchr(split[i], ',') && xyz == 2)
       {
            div = ft_split(split[i], ',');
            pl->rgb = (t_col *)ft_calloc(3, sizeof(t_col));
            pl->rgb->r = ft_atof(div[0]);
            pl->rgb->g = ft_atof(div[1]);
            pl->rgb->b = ft_atof(div[2]);
            xyz++;
            free_char_pp(&div);
       }
    }
}