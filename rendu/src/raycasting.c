/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:43:08 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/26 17:43:13 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/wolf.h>

void			predda(t_w *w)
{
	if (w->rdir_x < 0)
	{
		w->step_x = -1;
		w->sdist_x = (w->rpos_x - w->map_x) * w->ddist_x;
	}
	else
	{
		w->step_x = 1;
		w->sdist_x = (w->map_x + 1.0 - w->rpos_x) * w->ddist_x;
	}
	if (w->rdir_y < 0)
	{
		w->step_y = -1;
		w->sdist_y = (w->rpos_y - w->map_y) * w->ddist_y;
	}
	else
	{
		w->step_y = 1;
		w->sdist_y = (w->map_y + 1.0 - w->rpos_y) * w->ddist_y;
	}
}

t_col			*color(void)
{
	static t_col	color[6] = {
		{255, 0, 0},
		{128, 0, 128},
		{0, 255, 0},
		{0, 128, 0},
		{0, 191, 255},
		{128, 128, 128}
	};

	return (color);
}

void			wall_hit(t_w *w)
{
	while (w->hit == 0)
	{
		if (w->sdist_x < w->sdist_y)
		{
			w->sdist_x += w->ddist_x;
			w->map_x += w->step_x;
			w->side = 0;
		}
		else
		{
			w->sdist_y += w->ddist_y;
			w->map_y += w->step_y;
			w->side = 1;
		}
		if (w->map[w->map_x][w->map_y] > 0)
			w->hit = 1;
	}
	if (w->side == 0)
		w->pwalldist = (w->map_x - w->rpos_x + (1 - w->step_x) / 2) / w->rdir_x;
	else
		w->pwalldist = (w->map_y - w->rpos_y + (1 - w->step_y) / 2) / w->rdir_y;
}

void			perspective(t_w *w, t_window *win)
{
	w->lineheight = (int)(win->widht / w->pwalldist);
	w->drawstart = win->widht / 2 - w->lineheight / 2;
	if (w->drawstart < 0)
		w->drawstart = 0;
	w->drawend = win->widht / 2 + w->lineheight / 2;
	if (w->drawend >= win->widht)
		w->drawend = win->widht - 1;
}

void			raycasting(t_env *env)
{
	int		x;

	x = 0;
	while (x < env->win->widht)
	{
		launch_ray(env->w, env->win, x);
		env->w->hit = 0;
		predda(env->w);
		wall_hit(env->w);
		perspective(env->w, env->win);
		draw(env, x);
		x++;
	}
}
