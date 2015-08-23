//
//  main.c
//  GenerativeImage
//
//  Created by Eric McConville on 8/21/15.
//  Copyright (c) 2015 emcconville. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include <wand/MagickWand.h>

#include "vizsum.h"
#include "hashimg.h"
#include "algos.h" 

void usage(const char * p)
{
    const char * message = "Version: " VIZSUM_VERSION "\n"
    "Usage: %s [options ...] outfile\n"
    "\n"
    "Options:\n"
    "  Digest Algorithm:\n"
    "    -md5           MD5 message-digest algorithm\n"
    "    -sha1          SHA1 message-digest algorithm\n\n"
    "  Color Interpolate:\n"
    "    -barycentric   Use Barycentric Color Interpolate\n"
    "    -bilinear      Use Bilinear Color Interpolate\n"
    "    -polynomial    Use Polynomial Color Interpolate\n"
    "    -shepards      Use Shepards Color Interpolate\n"
    "    -voronoi       Use Voronoi Color Interpolate\n"
    "    -inverse       Use Inverse Color Interpolate\n"
    ;
    printf(message, p);
}

int main(int argc, const char * argv[]) {
    if (argc < 2) { usage(argv[0]); return 1; }
    
    MagickWand * wand;
    PixelWand * bg;
    SparseColorMethod method = BarycentricColorInterpolate;
    const char * outfile = NULL;
    enum alog algo_method = ALGO_MD5;
    int i;
    for (i=1; i < argc; i++) {
        if (strcmp(argv[i], "-barycentric") == 0) {
            method = BarycentricColorInterpolate;
        } else if (strcmp(argv[i], "-bilinear") == 0) {
            method = BilinearColorInterpolate;
        } else if (strcmp(argv[i], "-polynomial") == 0) {
            method = PolynomialColorInterpolate;
        } else if (strcmp(argv[i], "-shepards") == 0) {
            method = ShepardsColorInterpolate;
        } else if (strcmp(argv[i], "-voronoi") == 0) {
            method = VoronoiColorInterpolate;
        } else if (strcmp(argv[i], "-inverse") == 0) {
            method = InverseColorInterpolate;
        } else if (strcmp(argv[i], "-md5") == 0) {
            algo_method = ALGO_MD5;
        } else if (strcmp(argv[i], "-sha1") == 0) {
            algo_method = ALGO_SHA1;
        } else {
            if (argv[i][0] == '-') {
                fprintf(stderr, "Unknown options `%s'\n", argv[i]);
                usage(argv[0]);
                return 1;
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
        fprintf(stderr, "Outfile not defined.");
        usage(argv[0]);
        return 1;
    }

    struct context argument;
    argument.argument_count = 0;
    
    switch (algo_method) {
        case ALGO_MD5: {
            algo_populate_md5(&argument);
            break;
        }
        case ALGO_SHA1: {
            algo_populate_sha1(&argument);
            break;
        }
    }

    MagickWandGenesis();
    bg = NewPixelWand();
    PixelSetColor(bg, "white");
    wand = NewMagickWand();
    MagickNewImage(wand, 0xFF, 0xFF, bg);
    MagickSparseColorImage(wand,
                           AllChannels,
                           method,
                           argument.argument_count,
                           argument.arguments);
    MagickWriteImage(wand, outfile);
    DestroyPixelWand(bg);
    DestroyMagickWand(wand);
    MagickWandTerminus();

    return 0;
}
