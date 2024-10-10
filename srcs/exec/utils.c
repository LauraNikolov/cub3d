/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:44:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/10 14:33:30 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//check pos of angle on unit circle to adjust step
int	unit_circle(float angle, char c)
{
	if (c == 'x' && (angle > 0 && angle < M_PI))
		return (1);
	if (c == 'y' && (angle > (M_PI / 2) && angle < (3 * M_PI / 2)))
		return (1);
	return (0);
}

double	norm_angle(double x)
{
	x = fmod(x, 2 * M_PI);
	if (x < 0)
		x += 2 * M_PI;
	return (x);
}
