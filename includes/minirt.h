/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:57:15 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/25 13:41:53 by dmartiro         ###   ########.fr       */
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

#define PREF "A C L pl sp cy"
#define EPSILION 0.000000001
/*
	A  = AMBIENT LIGHT
	C  = CAMERA
	L  = LIGHT
	pl = PLANE
	sp = SPHERE
	cy = CYLINDER
*/

/*Initialization*/
t_table	*init_table(void);
void	init(t_table **table, t_scene **scene);


/*Vector*/

/*utils*/
char	*get_next_line(int fd);
char	*ft_strchr_gnl(const char *buffer, int ch);
char	*join(char *s1, char *s2);
char	*after(char *buffer);
char	*before(char *buffer);
void	failure(int errcode);

/*Parser*/
int 	parser(t_table *table, t_scene *scene, char *f);
void	collect_objects(t_table *table, t_scene *scene, char *line);
void	ambient(t_table *table, t_ambient *a_light, char **split);
void	camera(t_table *table, t_cam *camera, char **split);
void	collect_shapes(t_table *table, t_scene *scene, char *filename);
void	shape_counter(int *lpsc, char *filename);

/*Shapes*/
// void	lights(t_light **li, char *filename);
void    light(int led, t_scene *scene, char *filename);
void    plane(int pl, t_scene *scene, char *filename);

//prototypes
t_sp	*new_sp(t_vec3 *v, t_col *c, float r);


//Render
void	render(t_table *table, t_scene *scene);


//Resource Freeing
void	free_char_pp(char ***pp);

#endif