//
//  algos_gost.c
//  VizSum
//
//  Created by Eric McConville on 8/26/15.
//  Copyright (c) 2015 emcconville. All rights reserved.
//

#include "algos_gost.h"
#include "hashimg.h"
#include "gost.h"

void algo_populate_gost(struct context_heap * c, unsigned long flags)
{
    int i;
    unsigned char gost_digest[32];
    unsigned char content[ALGO_CONTEXT_BUFFER_LENGTH];
    size_t content_len = 0;
    struct sha1_map * map_ptr;
    struct hue_map * map_hue_ptr;
    GOST_CTX context;
    GOST_Init(&context);
    while (!feof(stdin)) {
        content_len = fread(content, 1, 1024, stdin);
        GOST_Update(&context, content, content_len);
        if (ferror(stdin)) {
            fprintf(stderr, "Error reading from stdin");
            break;
        }
    }
    GOST_Final(&context, gost_digest);

    if (flags) {
        for (i = 0; i < 10; i++) {
            map_hue_ptr = (struct hue_map *)(gost_digest + (sizeof(struct hue_map) * i));
            append_coord(c, &map_hue_ptr->v);
            append_hue(c, map_hue_ptr->h);
        }
    } else {
        for (i =0; i < 3; i++) {
            map_ptr = (struct sha1_map *)(gost_digest + (sizeof(struct sha1_map) * i));
            append_coord(c, &map_ptr->v1);
            append_color(c, &map_ptr->c1);
            append_coord(c, &map_ptr->v2);
            append_color(c, &map_ptr->c2);
        }
    }
}