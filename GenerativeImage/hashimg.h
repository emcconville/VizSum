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

void append_color(double * list, size_t * counter, struct color * c);
void append_coord(double * list, size_t * counter, struct coord * v);
void append_hue(double * list, size_t * counter, unsigned char h);

#endif /* defined(__GenerativeImage__hashimg__) */
