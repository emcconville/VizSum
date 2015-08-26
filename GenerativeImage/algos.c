//
//  algos.c
//  GenerativeImage
//
//  Created by Eric McConville on 8/22/15.
//  Copyright (c) 2015 emcconville. All rights reserved.
//

#include <string.h>

#include "algos.h"

static struct algos * algo_list;


struct algos * algo_register(struct algos * a)
{
    struct algos * node = algo_list;
    if (node == NULL) {
        node = algo_list = a;
    } else {
        while (node->next) { node = node->next; }
        node->next = a;
    }
    return algo_list;
}

struct algos * algo_find_by_argument_flag(const char * arg)
{
    struct algos * node = algo_list;
    size_t len = strlen(arg);
    while (node && len) {
        if (strncasecmp(node->argument_flag, arg, len) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}