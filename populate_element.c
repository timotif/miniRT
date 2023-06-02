/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfregni <tfregni@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:30:47 by tfregni           #+#    #+#             */
/*   Updated: 2023/06/02 13:39:50 by tfregni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_err	validate_ambient(t_scene *scene, char **el)
{
	if (ft_arrlen(el) != 3)
		return (ft_error("minirt: Ambient expects 2 parameters", \
				NULL, INVALID_ELEMENT));
	if (ft_isfloat(el[1]) && ft_atof(el[1]) >= 0 && ft_atof(el[1]) <= 1)
	{
		scene->ambient.lighting_ratio = ft_atof(el[1]);
		scene->ambient.trgb = extract_rgb(el[2]);
		return (SUCCESS);
	}
	return (ft_error("minirt: invalid argument: ", \
			el[1], INVALID_ELEMENT));
}

/**
 * Shall we set limits for the position? Maybe macroed in the header file
*/
t_err	validate_camera(t_scene *scene, char **el)
{
	if (ft_arrlen(el) != 4)
		return (ft_error("minirt: Camera expects 3 parameters", \
				NULL, INVALID_ELEMENT));
	scene->camera.pos = extract_xyz(el[1]);
	scene->camera.orientation = (t_vector)extract_xyz(el[2]);
	if (!validate_3d_range((t_point)scene->camera.orientation, -1.0, 1.0))
		return (ft_error("minirt: invalid argument: ", el[2], INVALID_ELEMENT));
	scene->camera.fov = ft_atoi(el[3]);
	if (scene->camera.fov < 0 || scene->camera.fov > 180)
		return (ft_error("minirt: invalid argument: ", el[3], INVALID_ELEMENT));
	return (SUCCESS);
}

t_err	validate_light(t_scene *scene, char **el)
{
	if (ft_arrlen(el) > 4 || ft_arrlen(el) < 3)
		return (ft_error("minirt: Light expects 2 or 3 parameters", \
				NULL, INVALID_ELEMENT));
	scene->light.pos = extract_xyz(el[1]);
	if (ft_isfloat(el[2]) && ft_atof(el[2]) >= 0 && ft_atof(el[2]) <= 1)
	{
		scene->light.brightness = ft_atof(el[2]);
		scene->light.trgb = extract_rgb(el[3]);
		return (SUCCESS);
	}
	return (ft_error("minirt: invalid argument: ", \
			el[2], INVALID_ELEMENT));
}
