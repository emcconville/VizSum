//
//  algos_md5.c
//  VizSum
//
//  Created by Eric McConville on 8/25/15.
//  Copyright (c) 2015 emcconville. All rights reserved.
//

#include "algos_md5.h"
#include "hashimg.h"
#include "md5.h"

#pragma mark md5

void algo_hash_md5(unsigned char * md5_digest)
{
    unsigned char content[ALGO_CONTEXT_BUFFER_LENGTH];
    size_t content_len = 0;
    md5_state_t state;
    md5_init(&state);
    while (!feof(stdin)) {
        content_len = fread(content, 1, 1024, stdin);
        md5_append(&state, (const md5_byte_t *)content, (int)content_len);
        if (ferror(stdin)) {
            fprintf(stderr, "Error reading from stdin");
            break;
        }
    }
    md5_finish(&state, (md5_byte_t *)md5_digest);
}


void algo_populate_md5(struct context_heap * c, unsigned long flags)
{
    unsigned char md5_digest[16];
    struct md5_map * map_ptr;
    struct hue_map * map_hue_ptr;
    struct coord * FIRST_PIXEL = &(struct coord){0x00, 0x00};
    struct coord * LAST_PIXEL  = &(struct coord){0xFF, 0xFF};
    algo_hash_md5(md5_digest);
    if (flags) {
        int i;
        for ( i=0; i < 5; i++ ) {
            map_hue_ptr = (struct hue_map *)(md5_digest + (sizeof(struct hue_map) * i));
            append_coord(c, &map_hue_ptr->v);
            append_hue(c, map_hue_ptr->h);
        }
    } else {
        map_ptr = (struct md5_map *)md5_digest;
        append_coord(c, &map_ptr->v1);
        append_color(c, &map_ptr->c1);
        append_coord(c, &map_ptr->v2);
        append_color(c, &map_ptr->c2);
        append_coord(c, FIRST_PIXEL);
        append_color(c,  &map_ptr->cs);
        append_coord(c, LAST_PIXEL);
        append_color(c,  &map_ptr->ce);
    }
}
