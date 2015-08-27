//
//  algos.c
//  GenerativeImage
//
//  Created by Eric McConville on 8/22/15.
//  Copyright (c) 2015 emcconville. All rights reserved.
//

#include <string.h>

#include "algos.h"
#include "algos/algos_md5.h"
#include "algos/algos_sha1.h"
#include "algos/algos_adler32.h"
#include "algos/algos_whirlpool.h"
#include "algos/algos_gost.h"

#define ALGO_TYPE_COUNT 5

static struct algos algos_list[ALGO_TYPE_COUNT] = {
    {"-md5", algo_populate_md5}, // Default
    {"-sha1",algo_populate_sha1},
    {"-adler32",algo_populate_adler32},
    {"-whirlpool",algo_populate_whirlpool},
    {"-gost",algo_populate_gost}
};

struct algos * algo_find_by_argument_flag(const char * arg)
{
    struct algos * node;
    size_t len = strlen(arg);
    int i;
    for ( i = 0 ; i < ALGO_TYPE_COUNT; i++ ) {
        node = &algos_list[i];
        if (strncasecmp(node->argument_flag, arg, len) == 0) {
            return node;
        }
    }
    return NULL;
}
