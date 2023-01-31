/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 05:09:15 by dmartiro          #+#    #+#             */
/*   Updated: 2023/01/31 22:20:47 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int parser(char *f)
{
    int     fd;
    char    *line;
    char    *basis;
    char    **split;
    
    (void)*line;
    basis = "";
    fd = open(f, O_RDONLY, 0644);
    if (fd == -1)
        return (-4);
    line = get_next_line(fd);
    
    
    return (0);
}