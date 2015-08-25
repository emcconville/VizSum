//
//  vizsum-types.h
//  VizSum
//
//  Created by Eric McConville on 8/25/15.
//  Copyright (c) 2015 emcconville. All rights reserved.
//

#ifndef VizSum_vizsum_types_h
#define VizSum_vizsum_types_h

#define ALGO_CONTEXT_BUFFER_LENGTH 1024

/*!
 * @struct context
 * @abstract Holds flat list of doubles for MagickSparseColorImage.
 * @seealso MagickSparseColorImage
 */
struct context {
    size_t argument_count;
    double arguments[ALGO_CONTEXT_BUFFER_LENGTH];
};


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

struct hue_map {
    struct coord v;
    unsigned char h;
};

enum alog { ALGO_MD5 = 1, ALGO_SHA1 = 2, ALGO_HUE = 4 };


#endif
