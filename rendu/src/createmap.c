/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 16:08:09 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/18 16:08:29 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void		mallocmap(t_w *w)
{
	int i;

	i = 0;
	w->map = (int **)ft_memalloc(sizeof(int *) * 22);
	while (i < 22)
	{
		w->map[i] = (int *)ft_memalloc(sizeof(int) * 22);
		i++;
	}
}

static void		fillone(t_w *w, int i)
{
	int j;

	j = 0;
	while (j < 22)
	{
		w->map[i][j] = 1;
		j++;
	}
}

static void		fillcentre(t_w *w, int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (j < 22)
	{
		if (j <= 1 || j >= 20)
			w->map[i][j] = 1;
		else
		{
			if (j % 2 == 0)
				w->map[i][j] = 0;
			else
			{
				w->map[i][j] = (2 + k);
				k++;
				if (2 + k > 5)
					k = 0;
			}
		}
		j++;
	}
}

static void		filldoors(t_w *w)
{
	int i;
	int j;
	int l;

	j = 3;
	l = 1;
	while (j < 19)
	{
		i = 2;
		if (l == 1)
		{
			w->map[10][j] = 0;
			w->map[11][j] = 0;
			w->map[12][j] = 0;
		}
		else
		{
			w->map[5][j] = 0;
			w->map[6][j] = 0;
			w->map[15][j] = 0;
			w->map[16][j] = 0;
		}
		l *= -1;
		j += 2;
	}
}

void			createmap(t_w *w)
{
	int i;

	i = 0;
	mallocmap(w);
	while (i < 22)
	{
		if ((i <= 1) || (i >= 20))
			fillone(w, i);
		else
			fillcentre(w, i);
		i++;
	}
	filldoors(w);
	w->map[7][19] = 0;
}
