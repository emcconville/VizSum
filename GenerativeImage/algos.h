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

/*! @enum algos_flags Indeicate additional run-time options. */
enum algos_flags {
    /*! No flags given. */
    UndefinedFlag,
    /*! Only render hue values. */
    HueOnlyFlag,
};

/*!
 * @struct algos
 * @abstract Hold run-time argument flag, and function pointer.
 */
struct algos {
    /*! String to match against. */
    const char * argument_flag;
    /*!
     * @abstract Populate context heap by applying algorithm, and
     *           generate list of doubles.
     */
    void (*populate)(struct context_heap * c, unsigned long flags);
};

/*!
 * @abstract Iterate over known algorithms and return matching structure.
 * @param arg User given flag.
 * @returns Matching algorithm, or NULL.
 */
struct algos * algo_find_by_argument_flag(const char * arg);

#endif /* defined(__GenerativeImage__algos__) */
