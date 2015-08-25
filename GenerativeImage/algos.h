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

struct context {
    size_t argument_count;
    double arguments[ALGO_CONTEXT_BUFFER_LENGTH];
};

void algo_hash_md5(unsigned char * md5_digest);
void algo_populate_md5(struct context * c);
void algo_populate_md5_hue(struct context * c);
void algo_hash_sha1(unsigned char * sha1_digest);
void algo_populate_sha1(struct context * c);
void algo_populate_sha1_hue(struct context * c);

#endif /* defined(__GenerativeImage__algos__) */
