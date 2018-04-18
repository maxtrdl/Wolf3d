/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:38:53 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/19 11:38:56 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/wolf.h>

void	init_play(t_w *w)
{
	w->pos_x = 12;
	w->pos_y = 11;
	w->dir_x = -1;
	w->dir_y = 0;
	w->plane_x = 0;
	w->plane_y = 0.66;
}

void	init_wolf(t_env *env)
{
	createmap(env->w);
	init_play(env->w);
}

void	mlx_init_img(t_env *env)
{
	env->image->img = mlx_new_image(env->win->mlx, \
			env->win->widht, env->win->height);
	env->image->data = mlx_get_data_addr(env->image->img\
			, &env->image->bpp, &env->image->sl, &env->image->ed);
}

void	mlx_init_win(t_env *env)
{
	env->win->mlx = mlx_init();
	env->win->widht = 800;
	env->win->height = 800;
	env->win->fen = mlx_new_window(env->win->mlx\
			, env->win->widht, env->win->height, "wolf3d");
	mlx_init_img(env);
}

int		init_env(t_env *env)
{
	if (!(env->win = (t_window *)malloc(sizeof(t_window))))
		return (0);
	if (!(env->image = (t_image *)malloc(sizeof(t_image))))
		return (0);
	if (!(env->w = (t_w *)malloc(sizeof(t_w))))
		return (0);
	return (1);
}
