//
//  algos_adler32.c
//  VizSum
//
//  Created by Eric McConville on 8/25/15.
//  Copyright (c) 2015 emcconville. All rights reserved.
//

#include "algos_adler32.h"
#include "hashimg.h"
#include "adler32.h"

void algo_hash_adler32(unsigned char * adler32_digest)
{
    unsigned char content[ALGO_CONTEXT_BUFFER_LENGTH];
    size_t content_len = 0;
    
    ADLER32_CTX context;
    ADLER32_Init(&context);
    while (!feof(stdin)) {
        content_len = fread(content, 1, 1024, stdin);
        ADLER32_Update(&context, (const uint8_t *)content, content_len);
        if (ferror(stdin)) {
            fprintf(stderr, "Error reading from stdin");
            break;
        }
    }
    ADLER32_Final(&context, adler32_digest);

}

void algo_populate_adler32(struct context_heap * c, unsigned long flags)
{
    unsigned char adler32_digest[ADLER32_DIGEST_SIZE];
    algo_hash_adler32(adler32_digest);
    struct coord P;
    int i;
    for ( i = 0; i < ADLER32_DIGEST_SIZE; i+=2 ) {
        P.x = ((adler32_digest[i] >> 4) << 4);
        P.y = ((adler32_digest[i]) << 4) ;
        append_coord(c, &P);
        append_hue(c, adler32_digest[i+1]);
    }

}