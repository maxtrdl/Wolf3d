/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:10:09 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/26 13:10:58 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

int				loop(t_env *env)
{
	env->w->move_s = 0.008 * 12;
	env->w->rot_s = 0.008 * 6;
	if (env->w->up == 1)
	{
		env->w->up = 0;
		raycasting(env);
		mlx_put_image_to_window(env->win->mlx, \
			env->win->fen, env->image->img, 0, 0);
	}
	return (0);
}

static void		print_image(t_env *env)
{
	mlx_hook(env->win->fen, 2, (1L << 0), get_key, env);
	mlx_hook(env->win->fen, 17, (1L << 17), red_cross, env);
	mlx_loop_hook(env->win->mlx, loop, env);
	mlx_loop(env->win->mlx);
}

int				main(int ac, char **av)
{
	t_env		*env;

	if (ac != 1)
	{
		ft_putendl("usage : ./wolf3d [no argument needed]");
		av[1] = NULL;
		return (-1);
	}
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (-1);
	if (!(init_env(env)))
		return (-1);
	mlx_init_win(env);
	env->w->up = 1;
	env->color = color();
	init_wolf(env);
	raycasting(env);
	mlx_put_image_to_window(env->win->mlx, \
		env->win->fen, env->image->img, 0, 0);
	print_image(env);
	return (1);
}
