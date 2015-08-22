//
//  algos.c
//  GenerativeImage
//
//  Created by Eric McConville on 8/22/15.
//  Copyright (c) 2015 emcconville. All rights reserved.
//

#include "algos.h"
#include "hashimg.h"
#include "md5.h"
#include "sha1.h"


void algo_populate_md5(struct context * c)
{
    unsigned char content[ALGO_CONTEXT_BUFFER_LENGTH];
    size_t content_len = 0;
    struct md5_map * map_ptr;
    struct coord * FIRST_PIXEL = &(struct coord){0x00, 0x00};
    struct coord * LAST_PIXEL  = &(struct coord){0xFF, 0xFF};
    

    md5_state_t state;
    md5_byte_t md5_digest[16];
    md5_init(&state);
    while (!feof(stdin)) {
        content_len = fread(content, 1, 1024, stdin);
        md5_append(&state, (const md5_byte_t *)content, (int)content_len);
        if (ferror(stdin)) {
            fprintf(stderr, "Error reading from stdin");
            break;
        }
    }
    md5_finish(&state, md5_digest);
    map_ptr = (struct md5_map *)md5_digest;
    append_coord(c->arguments, &c->argument_count, &map_ptr->v1);
    append_color(c->arguments, &c->argument_count, &map_ptr->c1);
    append_coord(c->arguments, &c->argument_count, &map_ptr->v2);
    append_color(c->arguments, &c->argument_count, &map_ptr->c2);
    append_coord(c->arguments, &c->argument_count, FIRST_PIXEL);
    append_color(c->arguments, &c->argument_count,  &map_ptr->cs);
    append_coord(c->arguments, &c->argument_count, LAST_PIXEL);
    append_color(c->arguments, &c->argument_count,  &map_ptr->ce);
}

void algo_populate_sha1(struct context * c)
{
    unsigned char content[ALGO_CONTEXT_BUFFER_LENGTH];
    size_t content_len = 0;
    int i;
    struct sha1_map * map_ptr;
    SHA1_CTX context;
    unsigned char sha1_digest[SHA1_DIGEST_SIZE];
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
    for ( i = 0; i < 2; i++) {
        map_ptr = (struct sha1_map *)(sha1_digest + (sizeof(struct sha1_map) * i));
        append_coord(c->arguments, &c->argument_count, &map_ptr->v1);
        append_color(c->arguments, &c->argument_count, &map_ptr->c1);
        append_coord(c->arguments, &c->argument_count, &map_ptr->v2);
        append_color(c->arguments, &c->argument_count, &map_ptr->c2);
    }
}