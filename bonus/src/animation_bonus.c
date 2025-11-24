/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:22:05 by aaboudra          #+#    #+#             */
/*   Updated: 2025/11/24 22:30:56 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void reset_anim(t_anim *anim, t_data *data)
{
    int i;
    
    i = 0;
    anim->current_frame = 0;
    anim->counter = 0;
    anim->frame_delay = 2;
    anim->total_frames = 0;
    anim->playing = true;
    anim->data = data;
    anim->win_w = WIDTH;
    anim->win_h = HEIGHT;
    while (i < 41)
    {
        anim->frames[i] = NULL;
        i++;
    }
}

static void int_to_str(int n, char *buf)
{
    if (n < 10)
    {
        buf[0] = n + '0';
        buf[1] = '\0';
    }
    else
    {
        buf[0] = (n / 10) + '0';
        buf[1] = (n % 10) + '0';
        buf[2] = '\0';
    }
}

static mlx_image_t *load_frame(t_data *data, int idx)
{
    char path[256];
    char number[3];

    int_to_str(idx + 1, number);
    strcpy(path, "./bonus/frames/frame");
    strcat(path, number);
    strcat(path, ".png");
    mlx_texture_t *tex = mlx_load_png(path);
    if (!tex)
        return NULL;
    mlx_image_t *img = mlx_texture_to_image(data->mlx, tex);
    mlx_delete_texture(tex);
    return img;
}

void init_anim(t_anim *anim, t_data *data)
{
    int i;
    
    i = 0;
    reset_anim(anim, data);
    while (i < 41)
    {
        mlx_image_t *img = load_frame(data, i + 1);
        if (!img) continue;

        anim->frames[anim->total_frames] = img;
        anim->total_frames++;
        img->enabled = false;
        i++;
    }
    if (anim->total_frames == 0)
    {
        printf("error: no frames loaded\n");
        return;
    }
    mlx_image_t *first = anim->frames[0];
    first->enabled = true;
    mlx_resize_image(first, anim->win_w, anim->win_h);
    mlx_image_to_window(data->mlx, first, 0, 0);
}
void animation(void *param)
{
    t_anim *anim;

    anim = (t_anim *)param;
    if (!anim->playing || anim->total_frames == 0)
        return;
    anim->counter++;
    if (anim->counter < anim->frame_delay)
        return;
    anim->counter = 0;
    mlx_image_t *old = anim->frames[anim->current_frame];
    old->enabled = false;
    anim->current_frame = (anim->current_frame + 1) % anim->total_frames;
    mlx_image_t *new = anim->frames[anim->current_frame];
    new->enabled = true;
    mlx_resize_image(new, anim->win_w, anim->win_h);
    mlx_image_to_window(anim->data->mlx, new, 0, 0);
}

