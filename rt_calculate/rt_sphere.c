/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:37:07 by rjeong            #+#    #+#             */
/*   Updated: 2023/08/21 21:37:09 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_ray	cal_hit_point(double q1, double q2, t_ray const *cam, t_point const *sp)
{
	t_ray	ret;
	t_point	p1;
	t_point	p2;

	p1 = add_vec(cam->loc, multiply_vec(q1, cam->vec));
	p2 = add_vec(cam->loc, multiply_vec(q2, cam->vec));
	if (cal_distance(p1, cam->loc) > cal_distance(p2, cam->loc))
		rt_swap_point(&p1, &p2);
	if (rt_inner_prod(normalize_vec(rt_get_vec(p1, cam->loc)), cam->vec) < 0)
		rt_swap_point(&p1, &p2);
	ret.loc = p1;
	ret.vec = rt_get_vec(ret.loc, *sp);
	if (rt_inner_prod(ret.vec, cam->vec) > 0)
		ret.vec = multiply_vec(-1, ret.vec);
	return (ret);
}

int	cal_eq_sp(t_sphere const *sphere, t_ray const *cam, t_ray *ret)
{
	t_q_e_c	coef;

	coef.a = pow(cam->vec.x, 2) + pow(cam->vec.y, 2) + pow(cam->vec.z, 2);
	coef.b = 2 * (cam->vec.x * (cam->loc.x - sphere->loc.x)
			+ cam->vec.y * (cam->loc.y - sphere->loc.y)
			+ cam->vec.z * (cam->loc.z - sphere->loc.z));
	coef.c = pow(sphere->loc.x - cam->loc.x, 2)
		+ pow(sphere->loc.y - cam->loc.y, 2)
		+ pow(sphere->loc.z - cam->loc.z, 2)
		- pow(sphere->diameter, 2);
	coef.d = pow(coef.b, 2) - 4 * coef.a * coef.c;
	if (coef.d < 0)
		return (0);
	*ret = cal_hit_point((-coef.b + sqrt(coef.d)) / (2 * coef.a),
			(-coef.b - sqrt(coef.d)) / (2 * coef.a),
			cam, &sphere->loc);
	if (rt_inner_prod(rt_get_vec(ret->loc, cam->loc), cam->vec) < 0)
		return (0);
	return (1);
}

int	cal_sphere(t_sphere *list, t_ray *cam, t_ray *hit_point, int flag)
{
	t_ray	temp;

	while (list)
	{
		if (cal_eq_sp(list, cam, &temp))
		{
			if (flag == 0)
			{
				*hit_point = temp;
				hit_point->col = list->color;
				flag = 1;
			}
			else if (cal_distance(hit_point->loc, cam->loc) \
					> cal_distance(temp.loc, cam->loc))
			{
				*hit_point = temp;
				hit_point->col = list->color;
			}
		}
		list = list->next;
	}
	return (flag);
}

int	check_sphere(t_sphere *list, t_ray *hit, t_point light, int flag)
{
	t_ray	temp;

	while (list)
	{
		if (cal_eq_sp(list, hit, &temp)
			&& cal_distance(hit->loc, light) > cal_distance(hit->loc, temp.loc))
		{
			if (flag == 0)
				flag = 1;
		}
		list = list->next;
	}
	return (flag);
}
