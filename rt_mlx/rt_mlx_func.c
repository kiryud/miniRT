/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijeong <jijeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:29:27 by jijeong           #+#    #+#             */
/*   Updated: 2023/08/16 17:29:28 by jijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	rt_keyhook(int k, t_mlxlist *mlx)
{
	if (k == 53)
		rt_end(mlx);
	if (k == 15)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_image(mlx->mlx, mlx->img);
		rt_init(mlx->list->ac, mlx->list->av, mlx->list);
		rt_print_list_data(mlx->list);
		rt_set_mlx(mlx, mlx->list);
		rt_get_img(mlx, mlx->list);
		rt_clear_data(mlx->list);
		rt_display_mlx(mlx, mlx->list->av[0]);
	}
	return (0);
}

int	rt_end(t_mlxlist *mlx)
{
	printf("miniRT : good bye!\n");
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img);
	system("leaks miniRT");
	exit(0);
	return (0);
}
