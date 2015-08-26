//
//  sha1.c
//  VizSum
//
//  Created by Eric McConville on 8/25/15.
//  Copyright (c) 2015 emcconville. All rights reserved.
//

#include <stdio.h>

#include "algos_sha1.h"
#include "hashimg.h"
#include "sha1.h"


#pragma mark sha1

void algo_hash_sha1(unsigned char * sha1_digest)
{
    unsigned char content[ALGO_CONTEXT_BUFFER_LENGTH];
    size_t content_len = 0;
    
    SHA1_CTX context;
    SHA1_Init(&context);
    while (!feof(stdin)) {
        content_len = fread(content, 1, 1024, stdin);
        SHA1_Update(&context, (const uint8_t *)content, content_len);
        if (ferror(stdin)) {
            fprintf(stderr, "Error reading from stdin");
            break;
        }
    }
    SHA1_Final(&context, sha1_digest);
}


void algo_populate_sha1(struct context_heap * c, unsigned long flags)
{
    int i;
    struct sha1_map * map_ptr;
    struct hue_map * map_hue_ptr;
    unsigned char sha1_digest[SHA1_DIGEST_SIZE];
    algo_hash_sha1(sha1_digest);
    if ( flags ) {
        for ( i=0; i < 6; i++ ) {
            map_hue_ptr = (struct hue_map *)(sha1_digest + (sizeof(struct hue_map) * i));
            append_coord(c, &map_hue_ptr->v);
            append_hue(c, map_hue_ptr->h);
        }
    } else {
        for ( i = 0; i < 2; i++) {
            map_ptr = (struct sha1_map *)(sha1_digest + (sizeof(struct sha1_map) * i));
            append_coord(c, &map_ptr->v1);
            append_color(c, &map_ptr->c1);
            append_coord(c, &map_ptr->v2);
            append_color(c, &map_ptr->c2);
        }
    }
}
