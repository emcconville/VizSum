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
struct context_heap {
    /*! Size of doubles in heap */
    size_t argument_count;
    /*! Head of double heap. */
    double arguments[104];
};


/*!
 * @struct coord
 * @abstract Object holding X,Y coordinate system.
 */
struct coord {
    /*! Vector points with values between 0x00 ~ 0xFF */
    unsigned char x, y;
};

/*!
 * @struct color
 * @abstract Object holding R,G,B color value.
 */
struct color {
    /*! Color channel value between 0x00 & 0xFF */
    unsigned char r,g,b;
};

/*!
 * @struct md5_map
 * @abstract Map MD5 digest to point, and colors.
 */
struct md5_map {
    /*! Image X,Y points to assicate color with. */
    struct coord v1, v2;
    /*! Colors to render at points. */
    struct color c1, c2, cs, ce;
};

/*!
 * @struct sha1_map
 * @abstract Map SHA1 digest to point, and colors.
 */
struct sha1_map {
    /*! Image X,Y points to assicate color with. */
    struct coord v1, v2;
    /*! Colors to render at points. */
    struct color c1, c2;
};

/*!
 * @struct hue_map
 * @abstract Generic hue map that can be applied to any 3-byte algo.
 */
struct hue_map {
    /*! Image X,Y point to assicate color with. */
    struct coord v;
    /*! Angle of hue */
    unsigned char h;
};

#endif
