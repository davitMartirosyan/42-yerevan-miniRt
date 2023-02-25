/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:47:33 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/25 14:07:06 by dmartiro         ###   ########.fr       */
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