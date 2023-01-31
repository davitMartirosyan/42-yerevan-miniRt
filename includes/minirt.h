/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:57:15 by dmartiro          #+#    #+#             */
/*   Updated: 2023/01/31 21:40:04 by dmartiro         ###   ########.fr       */
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
# include "../mlx_linux/mlx.h"
# include <math.h>
# include "../libft/libft.h"
# include "structs.h"

/*Vector*/
t_vec		*vec(float x, float y, float z);
t_vec		*vecsubtract(t_vec *v1, t_vec *v2);
float		veclen(t_vec *vec);
void		vec_norm(t_vec *vec);
float		two_points(t_vec *v1, t_vec *v2);

/*utils*/
void		failure(int errcode);
char		*get_next_line(int fd);
char		*ft_strchr_gnl(const char *buffer, int ch);
char		*join(char *s1, char *s2);
char		*after(char *buffer);
char		*before(char *buffer);


/*Parser*/
int			parser(char *f);
#endif