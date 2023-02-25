/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:47:33 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/25 14:38:37 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void collect(t_sp *sp, char **split);

void    sphere(int sp, t_scene *scene, char *filename)
{
    t_spin  spin;
    int i;
    
    i = -1;
    spin.fd = open(filename, O_RDONLY);
    scene->spheres = (t_sp *)ft_calloc(4, (sp * sizeof(t_sp)));
    spin.line = get_next_line(spin.fd);
    while (spin.line)
    {
        spin.split = ft_split(spin.line, ' ');
        if (ft_strcmp(spin.split[0], "sp") == 0)
            collect(&scene->spheres[++i], spin.split);
        free_char_pp(&spin.split);
        free(spin.line);
        spin.line = get_next_line(spin.fd);
    }
}

static void collect(t_sp *sp, char **split)
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
            sp->cord = (t_vec3 *)ft_calloc(3, sizeof(t_vec3));
            sp->cord->x = ft_atof(div[0]);
            sp->cord->y = ft_atof(div[1]);
            sp->cord->z = ft_atof(div[2]);
            free_char_pp(&div);
            xyz++;
        }
        else if (ft_strchr(split[i], ',') && xyz == 1)
        {
             div = ft_split(split[i], ',');
             sp->rgb = (t_col *)ft_calloc(3, sizeof(t_col));
             sp->rgb->r = ft_atoi(div[0]);
             sp->rgb->g = ft_atoi(div[1]);
             sp->rgb->b = ft_atoi(div[2]);
             free_char_pp(&div);
             xyz++;
        }
        else
            sp->radius = ft_atof(split[i]);
    }
}