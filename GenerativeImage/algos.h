//
//  algos.h
//  GenerativeImage
//
//  Created by Eric McConville on 8/22/15.
//  Copyright (c) 2015 emcconville. All rights reserved.
//

#ifndef __GenerativeImage__algos__
#define __GenerativeImage__algos__

#include <stdio.h>

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

/*!
 * @abstract Fill pointer with MD5 digest information from STDIN
 * @param md5_digest Pointer to write digest.
 */
void algo_hash_md5(unsigned char * md5_digest);

/*!
 * @abstract Populate list of doubles with values extracted from MD5 digest.
 * @param c Context structure.
 */
void algo_populate_md5(struct context * c);

/*!
 * @abstract Populate list of doubles with values extracted from MD5 digest.
 * @discussion This method is identical to `algo_populate_md5`, but only poplates spares colors by hue angle.
 * @param c Structure/container to populate.
 * @seealso algo_populate_md5
 */
void algo_populate_md5_hue(struct context * c);

/*!
 * @abstract Fill pointer with SHA1 digest information from STDIN
 * @param sha1_digest Pointer to write digest.
 */
void algo_hash_sha1(unsigned char * sha1_digest);

/*!
 * @abstract Populate list of doubles with values extracted from SHA1 digest.
 * @param c Context structure.
 */
void algo_populate_sha1(struct context * c);

/*!
 * @abstract Populate list of doubles with values extracted from SHA1 digest.
 * @discussion This method is identical to `algo_populate_sha1`, but only poplates spares colors by hue angle.
 * @param c Structure/container to populate.
 * @seealso algo_populate_md5
 */
void algo_populate_sha1_hue(struct context * c);

#endif /* defined(__GenerativeImage__algos__) */
