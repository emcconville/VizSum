//
//  hashimg.c
//  GenerativeImage
//
//  Created by Eric McConville on 8/21/15.
//  Copyright (c) 2015 emcconville. All rights reserved.
//

#include "hashimg.h"
#include <wand/MagickWand.h>

double char_to_double(unsigned char byte)
{
    return byte / 255.0;
}

void append_color(double * list, size_t * counter, struct color * c)
{
    list[(*counter)++] = char_to_double(c->r); // Red channel
    list[(*counter)++] = char_to_double(c->g); // Green channel
    list[(*counter)++] = char_to_double(c->b); // Blue channel
    list[(*counter)++] = 1.0;                  // Index channel
    list[(*counter)++] = 1.0;                  // Opacity channel
}
void append_coord(double * list, size_t * counter, struct coord * v)
{
    list[(*counter)++] = (double)v->x;
    list[(*counter)++] = (double)v->y;
}

void append_hue(double * list, size_t * counter, unsigned char h)
{
    PixelWand * wand;
    wand = NewPixelWand();
    PixelSetHSL(wand, char_to_double(h), 1.0, 0.5);
    list[(*counter)++] = PixelGetRed(wand);    // Red channel
    list[(*counter)++] = PixelGetGreen(wand);  // Green channel
    list[(*counter)++] = PixelGetBlue(wand);   // Blue channel
    list[(*counter)++] = 1.0;                  // Index channel
    list[(*counter)++] = 1.0;                  // Opacity channel
    wand = DestroyPixelWand(wand);
}