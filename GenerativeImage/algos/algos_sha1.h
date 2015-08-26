//
//  sha1.h
//  VizSum
//
//  Created by Eric McConville on 8/25/15.
//  Copyright (c) 2015 emcconville. All rights reserved.
//

#ifndef __VizSum__algos__sha1__
#define __VizSum__algos__sha1__

#include "vizsum-types.h"

/*!
 * @abstract Fill pointer with SHA1 digest information from STDIN
 * @param sha1_digest Pointer to write digest.
 */
void algo_hash_sha1(unsigned char * sha1_digest);

/*!
 * @abstract Populate list of doubles with values extracted from SHA1 digest.
 * @param c Context structure.
 */
void algo_populate_sha1(struct context_heap * c, unsigned long flags);

#endif /* defined(__VizSum__algos__sha1__) */
