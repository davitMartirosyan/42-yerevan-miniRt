/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:18:15 by dmartiro          #+#    #+#             */
/*   Updated: 2023/03/03 20:32:38 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render(t_table *table, t_scene *scene)
{
	t_screen	*s;
	
	float spx = scene->spheres[0].cord->x;
	float spy = scene->spheres[0].cord->y;
	
	s = (t_screen *)malloc(sizeof(t_screen));
	s->w = table->w;
	s->h = table->h;
	
	s->cx = s->w / 2;
	s->cy = s->h / 2;
	
	s->mlx = mlx_init();
	s->mlx_win = mlx_new_window(s->mlx, s->w, s->h, "Unreal Engine 5.1");
	
	s->posy = 0;
	s->ty = 0;
	while (s->posy <= s->h)
	{
		s->posx = 0;
		s->tx = 0;
		while (s->posx <= s->w)
		{
			if (spx >= 0 && spy >= 0)
			{
				if ((s->posx == (spx + s->cx)) && (s->posy == (s->cy - spy)))
					mlx_pixel_put(s->mlx, s->mlx_win, s->posx, s->posy, 0xff0000);
				else
					mlx_pixel_put(s->mlx, s->mlx_win, s->posx, s->posy, 0x28c1a1);

			}
			else if (spx <= 0 && spy >= 0)
			{
				if ((s->posx == (spx + s->cx)) && s->posy == (s->cy - spy))
					mlx_pixel_put(s->mlx, s->mlx_win, s->posx, s->posy, 0xff0000);
				else
					mlx_pixel_put(s->mlx, s->mlx_win, s->posx, s->posy, 0x28c1a1);
			}
			else if (spx <= 0 && spy <= 0)
			{
				if (s->posx == (spx + s->cx) && s->posy == (s->cy - spy))
					mlx_pixel_put(s->mlx, s->mlx_win, s->posx, s->posy, 0xff0000);
				else
					mlx_pixel_put(s->mlx, s->mlx_win, s->posx, s->posy, 0x28c1a1);
			}
			else if (spx >= 0 && spy <= 0)
			{
				if (s->posx == (spx + s->cx) && s->posy == (s->cy - spy))
					mlx_pixel_put(s->mlx, s->mlx_win, s->posx, s->posy, 0xff0000);
				else
					mlx_pixel_put(s->mlx, s->mlx_win, s->posx, s->posy, 0x28c1a1);
			}
			else
				mlx_pixel_put(s->mlx, s->mlx_win, s->posx, s->posy, 0x28c1a1);
			s->posx++;
		}
		s->posy++;
	}
	mlx_loop(s->mlx);
}