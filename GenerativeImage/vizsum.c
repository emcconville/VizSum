//
//  main.c
//  GenerativeImage
//
//  Created by Eric McConville on 8/21/15.
//  Copyright (c) 2015 emcconville. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#if IMV == 7
#include <MagickWand/MagickWand.h>
#else
#include <wand/MagickWand.h>
#endif

#include "vizsum.h"
#include "vizsum-types.h"
#include "algos.h" 

void usage(const char * p)
{
    const char * message = "Version: " VIZSUM_VERSION " (c) E. McConville\n"
    "Usage: %s [options ...] outfile\n"
    "\n"
    "Options:\n"
    "  Digest Algorithm:\n"
    "    -adler32       Adler32 checksum algorithm.\n"
    "    -gost          GOST block cipher algorithm.\n"
    "    -md5           MD5 message-digest algorithm (default).\n"
    "    -sha1          SHA1 message-digest algorithm.\n"
    "    -whirlpool     WHIRLPOOL message-digest algorithm.\n"
    "\n"
    "  Color Interpolate:\n"
    "    -barycentric   Use Barycentric Color Interpolate (default).\n"
    "    -bilinear      Use Bilinear Color Interpolate.\n"
    "    -shepards      Use Shepards Color Interpolate.\n"
    "    -voronoi       Use Voronoi Color Interpolate.\n"
    "    -inverse       Use Inverse Color Interpolate.\n"
    "    -manhattan     Use Manhattan Color Interpolate.\n"
    "\n"
    "  Mode:\n"
    "    -hue           Only interprete digest values as hue degrees.\n"
    "\n"
    ;
    printf(message, p);
}

int main(int argc, const char * argv[]) {
    if (argc < 2) { usage(argv[0]); return 1; }

    MagickWand * wand;
    PixelWand * bg;
    ExceptionType err;
    char * message;
    SparseColorMethod method = BarycentricColorInterpolate;
    const char * outfile = NULL;
    unsigned long flags = UndefinedFlag;
    struct algos * algo_method = NULL;
    
    int i;
    for (i=1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            usage(argv[0]); return 0;
        } else if (strcmp(argv[i], "-?") == 0) {
            usage(argv[0]); return 0;
        } else if (strcmp(argv[i], "-barycentric") == 0) {
            method = BarycentricColorInterpolate;
        } else if (strcmp(argv[i], "-bilinear") == 0) {
            method = BilinearColorInterpolate;
        } else if (strcmp(argv[i], "-shepards") == 0) {
            method = ShepardsColorInterpolate;
        } else if (strcmp(argv[i], "-voronoi") == 0) {
            method = VoronoiColorInterpolate;
        } else if (strcmp(argv[i], "-inverse") == 0) {
            method = InverseColorInterpolate;
        } else if (strcmp(argv[i], "-manhattan") == 0) {
            method = ManhattanColorInterpolate;
        } else if (strcmp(argv[i], "-hue") == 0) {
            flags |= HueOnlyFlag;
        } else {
            if (argv[i][0] == '-') {
                algo_method = algo_find_by_argument_flag(argv[i]);
                if (algo_method == NULL) {
                    fprintf(stderr, "Unknown options `%s'\n", argv[i]);
                    usage(argv[0]);
                    return 1;
                }
            } else if (outfile != NULL) {
                fprintf(stderr, "Duplciate outfile `%s'\n", argv[i]);
                usage(argv[0]);
                return 1;
            } else {
                outfile = argv[i];
            }
        }
    }
    
    if ( outfile == NULL ) {
        fprintf(stderr, "Outfile not defined.\n");
        usage(argv[0]);
        return 1;
    }
    
    if (algo_method == NULL) {
        // Default
        algo_method = algo_find_by_argument_flag("-md5");
    }

    struct context_heap argument = {0};
    argument.argument_count = 0;

    algo_method->populate(&argument, flags);

    MagickWandGenesis();
    bg = NewPixelWand();
    PixelSetColor(bg, "white");
    wand = NewMagickWand();
    MagickNewImage(wand, 0xFF, 0xFF, bg);
    DestroyPixelWand(bg);
#if IMV == 7
    MagickSparseColorImage(wand, method, argument.argument_count, argument.arguments);
#else
    MagickSparseColorImage(wand,
                           RedChannel | GreenChannel | BlueChannel,
                           method,
                           argument.argument_count,
                           argument.arguments);
#endif
    message = MagickGetException(wand, &err);
    if ( err != UndefinedException ) {
        fprintf(stderr, "%s\n", message);
        RelinquishMagickMemory(message);
    } else {
        MagickWriteImage(wand, outfile);
        message = MagickGetException(wand, &err);
        if ( err != UndefinedException ) {
            fprintf(stderr, "%s\n", message);
            RelinquishMagickMemory(message);
        }
    }
    DestroyMagickWand(wand);
    MagickWandTerminus();

    return 0;
}
