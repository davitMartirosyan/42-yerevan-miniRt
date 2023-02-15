/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:57:15 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/15 20:19:41 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define BUFFER_SIZE 42
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <string.h>
# include <math.h>
# include "../mlx_mms/mlx.h"
# include "structs.h"
# include "prototype.h"
# include "proto.h"
# include "../libft/libft.h"

/*Vector*/


/*utils*/
char	*get_next_line(int fd);
char	*ft_strchr_gnl(const char *buffer, int ch);
char	*join(char *s1, char *s2);
char	*after(char *buffer);
char	*before(char *buffer);
void	failure(int errcode);

/*Parser*/
int parser(t_scene *scene, char *f);

//prototypes
t_sp	*new_sp(t_vec3 *v, t_col *c, float r);


//Render
void	render(t_scene *scene);

#endif