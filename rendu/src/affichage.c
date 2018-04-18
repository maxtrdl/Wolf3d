/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 16:05:57 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/10 11:05:59 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void			launch_ray(t_w *w, t_window *win, int x)
{
	w->camera_x = (2 * x) / (double)win->widht - 1;
	w->rpos_x = w->pos_x;
	w->rpos_y = w->pos_y;
	w->rdir_x = w->dir_x + w->plane_x * w->camera_x;
	w->rdir_y = w->dir_y + w->plane_y * w->camera_x;
	w->map_x = (int)w->rpos_x;
	w->map_y = (int)w->rpos_y;
	w->ddist_x = sqrt(1 + (w->rdir_y * \
		w->rdir_y) / (w->rdir_x * w->rdir_x));
	w->ddist_y = sqrt(1 + (w->rdir_x * \
		w->rdir_x) / (w->rdir_y * w->rdir_y));
}

void			get_color(t_w *w, int y)
{
	if (y < w->drawstart)
		w->c = 4;
	else if (y > w->drawend)
		w->c = 5;
	else if (w->side == 0 && w->rdir_x < 0)
		w->c = 0;
	else if (w->side == 0)
		w->c = 1;
	else if (w->rdir_y < 0)
		w->c = 2;
	else if (w->rdir_y > 0)
		w->c = 3;
}

static void		pixel_image(t_env *env, int x, int y)
{
	x = x * env->image->bpp / 8;
	y = y * env->image->sl;
	env->image->data[x + 0 + y] = env->color[env->w->c].b;
	env->image->data[x + 1 + y] = env->color[env->w->c].g;
	env->image->data[x + 2 + y] = env->color[env->w->c].r;
}

void			draw(t_env *env, int x)
{
	int		y;

	y = 0;
	get_color(env->w, y);
	while (y < env->w->drawstart && y < 800)
	{
		pixel_image(env, x, y);
		y++;
	}
	get_color(env->w, y);
	while (y <= env->w->drawend && y < 800)
	{
		pixel_image(env, x, y);
		y++;
	}
	get_color(env->w, y);
	while (y < env->win->widht)
	{
		pixel_image(env, x, y);
		y++;
	}
}
