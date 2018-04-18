/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:53:46 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/17 10:54:07 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define K_UP 126
# define K_DWN 125
# define K_LFT 123
# define K_RGT 124
# define K_ESC 53

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

typedef struct		s_col
{
	char			r;
	char			g;
	char			b;
}					t_col;

typedef struct		s_w
{
	double			move_s;
	double			rot_s;
	int				up;
	int				map_w;
	int				map_h;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			olddir_x;
	double			dir_y;
	double			plane_x;
	double			oldplane_x;
	double			plane_y;
	double			camera_x;
	double			rpos_x;
	double			rpos_y;
	int				c;
	double			rdir_x;
	double			rdir_y;
	int				map_x;
	int				map_y;
	int				drawstart;
	int				drawend;
	double			sdist_x;
	double			sdist_y;
	double			ddist_x;
	double			ddist_y;
	double			pwalldist;
	double			lineheight;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				**map;
}					t_w;

typedef struct		s_window
{
	int				widht;
	int				height;
	void			*mlx;
	void			*fen;
}					t_window;

typedef struct		s_image
{
	void			*img;
	char			*data;
	int				bpp;
	int				sl;
	int				ed;
}					t_image;

typedef struct		s_env
{
	t_window		*win;
	struct timeval	t;
	t_col			*color;
	t_image			*image;
	t_w				*w;
}					t_env;

t_col				*color(void);
void				init_play(t_w *w);
void				init_wolf(t_env *env);
void				launch_ray(t_w *w, t_window *win, int x);
void				get_color(t_w *w, int y);
void				draw(t_env *env, int x);
int					get_key(int key_code, t_env *env);
int					event_key(t_env *env);
int					init_env(t_env *env);
int					red_cross(void);
void				initwolf(t_env *env);
void				predda(t_w *w);
void				wall_hit(t_w *w);
void				perspective(t_w *w, t_window *win);
void				raycasting(t_env *env);
void				mlx_init_win(t_env *env);
void				mlx_init_img(t_env *env);
void				createmap(t_w *w);
void				initplay(t_w *w);
void				zoom(int mouse_key, t_env *env);
int					loop(t_env *env);
#endif
