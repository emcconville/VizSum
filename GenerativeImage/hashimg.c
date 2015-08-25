//
//  hashimg.c
//  GenerativeImage
//
//  Created by Eric McConville on 8/21/15.
//  Copyright (c) 2015 emcconville. All rights reserved.
//

#include <wand/MagickWand.h>

#include "vizsum-types.h"

double char_to_double(unsigned char byte)
{
    return byte / 255.0;
}

void append_color(struct context_heap * list, struct color * c)
{
    list->arguments[list->argument_count++] = char_to_double(c->r); // Red channel
    list->arguments[list->argument_count++] = char_to_double(c->g); // Green channel
    list->arguments[list->argument_count++] = char_to_double(c->b); // Blue channel
    list->arguments[list->argument_count++] = 1.0;                  // Index channel
    list->arguments[list->argument_count++] = 1.0;                  // Opacity channel
}
void append_coord(struct context_heap * list, struct coord * v)
{
    list->arguments[list->argument_count++] = (double)v->x;
    list->arguments[list->argument_count++] = (double)v->y;
}

void append_hue(struct context_heap * list, unsigned char h)
{
    PixelWand * wand;
    wand = NewPixelWand();
    PixelSetHSL(wand, char_to_double(h), 1.0, 0.5);
    list->arguments[list->argument_count++] = PixelGetRed(wand);    // Red channel
    list->arguments[list->argument_count++] = PixelGetGreen(wand);  // Green channel
    list->arguments[list->argument_count++] = PixelGetBlue(wand);   // Blue channel
    list->arguments[list->argument_count++] = 1.0;                  // Index channel
    list->arguments[list->argument_count++] = 1.0;                  // Opacity channel
    wand = DestroyPixelWand(wand);
}