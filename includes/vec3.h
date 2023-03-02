/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:04:19 by dmartiro          #+#    #+#             */
/*   Updated: 2023/03/02 21:33:15 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_vec3	*vecsum(t_vec3 *v1, t_vec3 *v2);
t_vec3	*vecmul(t_vec3 *v1, float p);
t_vec3	*vecsub(t_vec3 *v1, t_vec3 *v2);
t_vec3	*vecnorm(t_vec3 *v1);
float	veclen(t_vec3 *v1);
