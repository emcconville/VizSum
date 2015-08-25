//
//  hashimg.h
//  GenerativeImage
//
//  Created by Eric McConville on 8/21/15.
//  Copyright (c) 2015 emcconville. All rights reserved.
//

#ifndef __GenerativeImage__hashimg__
#define __GenerativeImage__hashimg__

#include <stdio.h>
#include "vizsum-types.h"

/*!
 * @abstract Convert unsigned byte to scale between 0.0 ~ 1.0
 * @param byte Value to convert
 * @returns double
 */
double char_to_double(unsigned char byte);

/*!
 * @abstract Updated doubles list with color value
 * @param list Pointer to point container
 */
void append_color(struct context_heap * list, struct color * c);

/*!
 * @abstract Updated doubles list with coordinate value
 * @param list Pointer to point container
 */
void append_coord(struct context_heap * list, struct coord * v);

/*!
 * @abstract Updated doubles list with color value calculated from hue angle.
 * @param list Pointer to point container
 */
void append_hue(struct context_heap * list, unsigned char h);

#endif /* defined(__GenerativeImage__hashimg__) */
