/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 07:09:22 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/13 20:05:28 by dmartiro         ###   ########.fr       */
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
	t_vec3			*cord;
	t_col			*rgb;
	int				color;
	float			radius;
}	t_sp; // sphere

typedef struct s_cy
{
	t_vec3	*cord;
	t_vec3	*normal;
	t_col	*rgb;
	float	color;
	float	diameter;
	float	height;
}	t_cy; // cylinder

typedef struct s_pl
{
	t_vec3	*cord;
	t_vec3	*normal;
	t_col	*rgb;
	float	color;
}	t_pl; // plane

typedef struct s_cam
{
	t_vec3	*cord;
	float	hfov;
	float	vfov;
}	t_cam; //camera

typedef struct s_light
{
	t_vec3	*cord;
	t_col	*rgb;
	float	brightness;
}	t_light; // light

typedef struct s_ambient
{
	float	brightness;
	t_col	rgb;
	float	color;
}	t_ambient; // ambient light
