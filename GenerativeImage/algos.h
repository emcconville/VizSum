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
#include "vizsum-types.h"

enum algos_flags {
    UndefinedFlag,
    HueOnlyFlag,
};

struct algos {
    const char * argument_flag;
    void (*populate)(struct context_heap * c, unsigned long flags);
    struct algos * next;
};

struct algos * algo_register(struct algos * a);
struct algos * algo_find_by_argument_flag(const char * arg);

#endif /* defined(__GenerativeImage__algos__) */
