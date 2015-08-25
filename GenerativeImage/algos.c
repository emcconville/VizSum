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


void algo_populate_md5(struct context * c)
{
    unsigned char md5_digest[16];
    struct md5_map * map_ptr;
    struct coord * FIRST_PIXEL = &(struct coord){0x00, 0x00};
    struct coord * LAST_PIXEL  = &(struct coord){0xFF, 0xFF};
    algo_hash_md5(md5_digest);
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

void algo_populate_md5_hue(struct context * c)
{
    unsigned char md5_digest[16];
    struct hue_map * map_ptr;
    algo_hash_md5(md5_digest);
    int i;
    for ( i=0; i < 5; i++ ) {
        map_ptr = (struct hue_map *)(md5_digest + (sizeof(struct hue_map) * i));
        append_coord(c->arguments, &c->argument_count, &map_ptr->v);
        append_hue(c->arguments, &c->argument_count, map_ptr->h);
    }
}

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


void algo_populate_sha1(struct context * c)
{
    int i;
    struct sha1_map * map_ptr;
    unsigned char sha1_digest[SHA1_DIGEST_SIZE];
    algo_hash_sha1(sha1_digest);
    for ( i = 0; i < 2; i++) {
        map_ptr = (struct sha1_map *)(sha1_digest + (sizeof(struct sha1_map) * i));
        append_coord(c->arguments, &c->argument_count, &map_ptr->v1);
        append_color(c->arguments, &c->argument_count, &map_ptr->c1);
        append_coord(c->arguments, &c->argument_count, &map_ptr->v2);
        append_color(c->arguments, &c->argument_count, &map_ptr->c2);
    }
}

void algo_populate_sha1_hue(struct context * c)
{
    unsigned char sha1_digest[SHA1_DIGEST_SIZE];
    struct hue_map * map_ptr;
    algo_hash_sha1(sha1_digest);
    int i;
    for ( i=0; i < 6; i++ ) {
        map_ptr = (struct hue_map *)(sha1_digest + (sizeof(struct hue_map) * i));
        append_coord(c->arguments, &c->argument_count, &map_ptr->v);
        append_hue(c->arguments, &c->argument_count, map_ptr->h);
    }
}
