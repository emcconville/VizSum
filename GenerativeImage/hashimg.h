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

struct coord {
    unsigned char x, y;
};

struct color {
    unsigned char r,g,b;
};

struct md5_map {
    struct coord v1, v2;
    struct color c1, c2, cs, ce;
};

struct sha1_map {
    struct coord v1, v2;
    struct color c1, c2;
};

enum alog { ALGO_MD5, ALGO_SHA1 };

double char_to_double(unsigned char byte);

void append_color(double * list, size_t * counter, struct color * c);
void append_coord(double * list, size_t * counter, struct coord * v);


#endif /* defined(__GenerativeImage__hashimg__) */
