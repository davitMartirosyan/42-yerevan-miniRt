/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:57:15 by dmartiro          #+#    #+#             */
/*   Updated: 2023/01/28 07:13:49 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# include "structs.h"


//MLX windows
int close_window(int keycode, t_mlx_win *render);

#endif