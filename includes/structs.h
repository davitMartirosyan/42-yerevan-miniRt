/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 07:09:22 by dmartiro          #+#    #+#             */
/*   Updated: 2023/01/29 12:40:26 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_mlx_win t_mlx_win;
typedef struct s_unreal t_unreal;
typedef enum s_engine_types t_engine_types;

typedef struct s_mlx_win
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx_wind;

typedef struct s_unreal
{
	int		type;
	char	*typename;
	float	xyz[4];
	float	normal_vec[4];
	float	shader;
	float	width;
	float	height;
	int		rgb[3];
}	t_unreal;

typedef enum s_engine_types
{
	COMPONENT,
	CAMERA,
	LIGHT,
	OBJECT
}	t_engine_types;
