/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 07:09:22 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/01 01:21:39 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_unreal		t_unreal;
typedef	struct s_vec		t_vec;
typedef	struct s_rgb		t_rgb;
typedef struct	s_light		t_light;
typedef struct	s_cam		t_cam;
typedef struct	s_ambient	t_ambient;

typedef struct s_unreal
{
	char	*typecase;
	t_vec	*vec_xyz;
	t_vec	*vec_norm;
	float	acl_ratio;
	float	ratio;
	t_rgb	*rgb;
	struct s_unreal *next;
}	t_unreal;


typedef struct	s_ambient
{
	char	*c;
	int		type;
	float	ratio;
	t_rgb	*amb_light_color;
}	t_ambient;

typedef struct	s_cam
{
	char			*c;
	int				type;
	t_vec			*camera_mesh_vector;
	t_vec			*camera_normal_vector;
	float			hfov;
	float			vfov;
	float			width;
	float			height;
	struct s_cam	*next;
}	t_cam;

typedef struct	s_light
{
	char			*c;
	int				type;
	t_vec			*light_vector;
	float			ratio;
	t_rgb			*light_color;
	struct s_light	*next;
}	t_light;

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
