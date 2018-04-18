/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 10:18:20 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/09 14:46:01 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

int					red_cross(void)
{
	exit(EXIT_SUCCESS);
}

static void			move(int key_code, t_env *env)
{
	if (key_code == K_UP)
	{
		if (env->w->map[(int)(env->w->pos_x + env->w->dir_x * \
			env->w->move_s)][(int)env->w->pos_y] == 0)
			env->w->pos_x += env->w->dir_x * env->w->move_s;
		if (env->w->map[(int)env->w->pos_x][(int)(env->w->pos_y\
			+ env->w->dir_y * env->w->move_s)] == 0)
			env->w->pos_y += env->w->dir_y * env->w->move_s;
	}
	if (key_code == K_DWN)
	{
		if (env->w->map[(int)(env->w->pos_x - env->w->dir_x * \
			env->w->move_s)][(int)env->w->pos_y] == 0)
			env->w->pos_x -= env->w->dir_x * env->w->move_s;
		if (env->w->map[(int)env->w->pos_x][(int)(env->w->pos_y\
			- env->w->dir_y * env->w->move_s)] == 0)
			env->w->pos_y -= env->w->dir_y * env->w->move_s;
	}
}

static void			rotate_lft(t_env *env)
{
	env->w->olddir_x = env->w->dir_x;
	env->w->dir_x = env->w->dir_x * cos(env->w->rot_s) -\
		env->w->dir_y * sin(env->w->rot_s);
	env->w->dir_y = env->w->olddir_x * sin(env->w->rot_s) +\
		env->w->dir_y * cos(env->w->rot_s);
	env->w->oldplane_x = env->w->plane_x;
	env->w->plane_x = env->w->plane_x * cos(env->w->rot_s) \
		- env->w->plane_y * sin(env->w->rot_s);
	env->w->plane_y = env->w->oldplane_x * sin(env->w->rot_s) \
		+ env->w->plane_y * cos(env->w->rot_s);
}

static void			rotate(int key_code, t_env *env)
{
	if (key_code == K_RGT)
	{
		env->w->olddir_x = env->w->dir_x;
		env->w->dir_x = env->w->dir_x * cos(-(env->w->rot_s)) - \
			env->w->dir_y * sin(-(env->w->rot_s));
		env->w->dir_y = env->w->olddir_x * sin(-(env->w->rot_s)) + \
			env->w->dir_y * cos(-(env->w->rot_s));
		env->w->oldplane_x = env->w->plane_x;
		env->w->plane_x = env->w->plane_x * cos(-(env->w->rot_s)) - \
			env->w->plane_y * sin(-(env->w->rot_s));
		env->w->plane_y = env->w->oldplane_x * sin(-(env->w->rot_s)) \
			+ env->w->plane_y * cos(-(env->w->rot_s));
	}
	if (key_code == K_LFT)
	{
		rotate_lft(env);
	}
}

int					get_key(int key_code, t_env *env)
{
	if (key_code == K_ESC)
	{
		mlx_destroy_image(env->win->mlx, env->image->img);
		exit(1);
	}
	else if (key_code >= 123 && key_code <= 126)
	{
		env->w->up = 1;
		if (key_code == K_UP || key_code == K_DWN)
			move(key_code, env);
		else
			rotate(key_code, env);
	}
	return (0);
}
