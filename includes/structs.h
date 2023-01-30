/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 07:09:22 by dmartiro          #+#    #+#             */
/*   Updated: 2023/01/30 21:22:02 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_render	t_render;
typedef struct s_unreal		t_unreal;
typedef struct s_vec		t_vec;
typedef enum s_engine_types t_engine_types;
typedef	struct s_rgb		t_rgb;
typedef struct s_cam		t_cam;

typedef struct s_render
{
	void	*mlx;
	void	*mlx_win;
}	t_render;

typedef struct s_unreal
{
	int	type;
	char	*typecase;
	t_vec	*vec_xyz;
	t_vec	*vec_norm;
	float	abstract;
	t_rgb	*rgb;
}	t_unreal;

typedef	struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef	struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

typedef struct s_sphere
{
	t_vec	*xyz;
	float	radius;
}	t_sphere;

typedef struct s_cam
{
	t_vec	*origin;
	t_vec	*direction;
	float	hfov;
	float	vfov;
	float	dfov;
	float	width;
	float	height;
}	t_cam; 

typedef struct s_terrain
{
	t_cam		*cameras;
	t_sphere	*sphere;
	float		width;
	float		height;
}	t_terrain;

typedef enum s_engine_types
{
	COMPONENT,
	CAMERA,
	LIGHT,
	OBJECT
}	t_engine_types;
