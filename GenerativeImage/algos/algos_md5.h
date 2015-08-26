//
//  algos_md5.h
//  VizSum
//
//  Created by Eric McConville on 8/25/15.
//  Copyright (c) 2015 emcconville. All rights reserved.
//

#ifndef __VizSum__algos_md5__
#define __VizSum__algos_md5__

#include <stdio.h>
#include "vizsum-types.h"

/*!
 * @abstract Fill pointer with MD5 digest information from STDIN
 * @param md5_digest Pointer to write digest.
 */
void algo_hash_md5(unsigned char * md5_digest);

/*!
 * @abstract Populate list of doubles with values extracted from MD5 digest.
 * @param c Context structure.
 */
void algo_populate_md5(struct context_heap * c, unsigned long flags);

#endif /* defined(__VizSum__algos_md5__) */
