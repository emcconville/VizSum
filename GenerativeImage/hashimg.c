//
//  hashimg.c
//  GenerativeImage
//
//  Created by Eric McConville on 8/21/15.
//  Copyright (c) 2015 emcconville. All rights reserved.
//

#if IMV == 7
#include <MagickWand/MagickWand.h>
#else
#include <wand/MagickWand.h>
#endif

#include "vizsum-types.h"

#ifndef LIST_PUSH
#define LIST_PUSH(x, v) x->arguments[x->argument_count++] = v
#endif

double char_to_double(unsigned char byte)
{
    return byte / 255.0;
}

void append_color(struct context_heap * list, struct color * c)
{
    LIST_PUSH(list, char_to_double(c->r)); // Red channel
    LIST_PUSH(list, char_to_double(c->g)); // Green channel
    LIST_PUSH(list, char_to_double(c->b)); // Blue channel
#if IMV != 7
    LIST_PUSH(list, 1.0);                  // Index channel
    LIST_PUSH(list, 1.0);                  // Opacity channel
#endif
}
void append_coord(struct context_heap * list, struct coord * v)
{
    LIST_PUSH(list, (double)v->x);
    LIST_PUSH(list, (double)v->y);
}

void append_hue(struct context_heap * list, unsigned char h)
{
    PixelWand * wand;
    wand = NewPixelWand();
    PixelSetHSL(wand, char_to_double(h), 1.0, 0.5);
    LIST_PUSH(list, PixelGetRed(wand));    // Red channel
    LIST_PUSH(list, PixelGetGreen(wand));  // Green channel
    LIST_PUSH(list, PixelGetBlue(wand));   // Blue channel
#if IMV != 7
    LIST_PUSH(list, 1.0);                  // Index channel
    LIST_PUSH(list, 1.0);                  // Opacity channel
#endif
    wand = DestroyPixelWand(wand);
}