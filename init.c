/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:25:24 by hbuisser          #+#    #+#             */
/*   Updated: 2020/02/29 16:18:34 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_1(t_index *idx)
{
    idx->big->cameraX = 0;
    idx->big->mapX = 0;
    idx->big->rayDirY = 0;
    idx->big->rayDirX = 0;
	idx->big->rayDirY = 0;
    idx->big->mapX = 0;
	idx->big->mapY = 0;
	idx->big->sideDistX = 0;
    idx->big->sideDistY = 0;
	idx->big->deltaDistX = 0;
    idx->big->deltaDistY = 0;
	idx->big->perpWallDist = 0;
	idx->big->stepX = 0;
    idx->big->stepY = 0;
    idx->big->drawStart = 0;
    idx->big->drawEnd = 0;
    idx->big->lineHeight = 0;
    idx->big->wallHeight = 0;
    idx->tex->color_n = NULL;
    idx->tex->color_s = NULL;
    idx->tex->color_e = NULL;
}

void init_2(t_index *idx)
{
    idx->tex->color_w = NULL;
    idx->tex->texX = 0;
	idx->tex->texY = 0;
    idx->big->side = 0;
    idx->tex->step = 0;
	idx->tex->texPos = 0;
    idx->el->elem = NULL;
    idx->el->resolution_line = 0;
    idx->el->resolution_x = 0;
    idx->el->resolution_y = 0;
    idx->el->north_line = 0;
    idx->el->south_line = 0;
    idx->el->west_line = 0;
    idx->el->east_line = 0;
    idx->el->sprite_line = 0;
    idx->el->floor_line = 0;
    idx->el->ceilling_line = 0;
    idx->el->ceilling_color_r = 0;
    idx->el->ceilling_color_g = 0;
    idx->el->ceilling_color_b = 0;
	idx->el->floor_color_r = 0;
}

void init_3(t_index *idx)
{
    idx->el->floor_color_g = 0;
    idx->el->floor_color_b = 0;
	idx->el->c_color_hex = 0;
	idx->el->f_color_hex = 0;
	idx->el->n_path = NULL;
	idx->el->s_path = NULL;
	idx->el->w_path = NULL;
	idx->el->e_path = NULL;
    idx->el->spr_path = NULL;
    idx->parse->data = NULL;
    idx->parse->map_string = NULL;
    idx->parse->map_string_clean = NULL;
    idx->parse->map = NULL;
    idx->parse->line_nbr = 0;
    idx->parse->column_nbr = 0;
    idx->parse->pos_x_init = 0;
    idx->parse->pos_y_init = 0;
    idx->parse->dir = 0;
    idx->img->img = NULL;
    idx->img->addr = NULL;
    idx->img->bits_per_pixel = 0;
}

void init_4(t_index *idx)
{
    idx->img->line_length = 0;
    idx->img->endian = 0;
    idx->window->mlx_ptr = NULL;
    idx->window->mlx_win = NULL;
    idx->tex->color = NULL;
    idx->spr->numSprites = 0;
    idx->spr->numSprites = 0;
    idx->spr->spr_tex = NULL;
	idx->spr->sprWidth = 0;
	idx->spr->sprHeight = 0;
	idx->spr->spriteX = 0;
	idx->spr->spriteY = 0;
	idx->spr->invDet = 0;
	idx->spr->transformX = 0;
	idx->spr->transformY = 0;
	idx->spr->spriteScreenX = 0;
	idx->spr->vMoveScreen = 0;
	idx->spr->drawStartY = 0;
}

void init_5(t_index *idx)
{
    idx->spr->drawEndY = 0;
	idx->spr->drawStartX = 0;
	idx->spr->drawEndX = 0;
	idx->spr->stripe = 0;
	idx->spr->texX = 0;
	idx->spr->texY = 0;
    idx->big->oldDirX = 0;
    idx->big->oldPlaneX = 0;
}

void create_init(t_index *idx)
{
    init_1(idx);
    init_2(idx);
    init_3(idx);
    init_4(idx);
    init_5(idx);
}
