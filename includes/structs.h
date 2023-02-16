/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 07:09:22 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/17 00:20:04 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3; // vector coordinates

typedef struct s_col
{
	int	r;
	int	g;
	int	b;
}	t_col; // colors red - green - blue

typedef struct s_sp
{
	struct s_sp		*head;
	t_vec3			*cord;
	t_col			*rgb;
	int				color;
	float			radius;
	struct s_sp		*next;
}	t_sp; // sphere

typedef struct s_cy
{
	struct s_sp		*head;
	t_vec3	*cord;
	t_vec3	*normal;
	t_col	*rgb;
	float	color;
	float	diameter;
	float	height;
	struct s_cy	*next;
}	t_cy; // cylinder

typedef struct s_pl
{
	struct s_sp		*head;
	t_vec3	*cord;
	t_vec3	*normal;
	t_col	*rgb;
	float	color;
	struct s_pl	*next;
}	t_pl; // plane

typedef struct s_cam
{
	t_vec3	*cord;
	t_vec3	*normal;
	int		hfov;
	float	vfov;
}	t_cam; //camera

typedef struct s_light
{
	struct s_sp		*head;
	t_vec3	*cord;
	t_col	*rgb;
	float	brightness;
	struct s_sp		*next;
}	t_light; // light

typedef struct s_ambient
{
	float	brightness;
	t_col	*rgb;
	float	color;
}	t_ambient; // ambient light

typedef struct s_scene
{
	t_cam		*camera;
	t_light		*light;
	t_ambient	*ambient_light;
	t_sp		*spheres;
	t_cy		*cylinders;
	t_pl		*plane;
} t_scene;

typedef struct s_table
{
	int	ambient_count;
	int	camera_count;
	int	def;
}	t_table;