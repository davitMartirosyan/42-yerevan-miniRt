/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 07:09:22 by dmartiro          #+#    #+#             */
/*   Updated: 2023/01/30 19:21:29 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_mlx_win
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx_wind;

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

typedef enum s_engine_types
{
	COMPONENT,
	CAMERA,
	LIGHT,
	OBJECT
}	t_engine_types;
