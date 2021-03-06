# vizsum

A generative image exercise for converting checksum data into something visual.
ImageMagick's sparse-color interpolation methods are used to create stunning
unique images.

**Example**

    vizsum README.png < README.md

![README.png](README.png)

**How this works**

Take the following message digest

    echo -n emcconville | md5
    #=> 8a59b44064a204d569feec76645a6dcb

This project proposes that the data generated by a digest can map to a Pixel
data structure.

    ,---- X coordinate
    ||,-- Y coordinate
    ||||
    8a59b44064a204d569feec76645a6dcb
        |     |
        `-----+- color value

Or even a Hue only degree value.

    ,---- X coordinate
    ||,-- Y coordinate
    ||||
    8a59b44064a204d569feec76645a6dcb
        ||
        `-- hue angle

So any digest blob can _(unsafely)_ be cast to a C data structure

~~~c
struct pixel {
    struct coord {
        unsigned char x,y
    },
    struct color {
        unsigned char r,g,b
    } // or hue 
}
~~~

Scaling bytes against quantum colors results in some truly unique points of color.
See below for examples of diffrent ImageMagick Interpolation of each color.

## Barycentric Interpolate (default)

    echo -n emcconville | vizsum -barycentric sumimg.png

| Digest  | Flag                                       | Hue only |
|---------|--------------------------------------------|----------|
| Adler32 | `-barycentric -adler32`                    | `-barycentric -adler32 -hue` |
|         | _same as `-hue`_                           | ![adler32](./imgs/adler32_barycentric_hue.png) |
| GOST    | `-barycentric -gost`                       | `-barycentric -gost -hue` |
|         | ![GOST](./imgs/gost_barycentric.png)       | ![GOST](./imgs/gost_barycentric_hue.png) |
| MD5     | `-barycentric -md5`                        | `-barycentric -md5 -hue` |
|         | ![MD5](./imgs/md5_barycentric.png)         | ![MD5](./imgs/md5_barycentric_hue.png) |
| SHA1    | `-barycentric -sha1`                       | `-barycentric -sha1 -hue` |
|         | ![SHA1](./imgs/sha1_barycentric.png)       | ![SHA1](./imgs/sha1_barycentric_hue.png) |
| WHIRLPOOL | `-barycentric -whirlpool`                | `-barycentric -whirlpool -hue` |
|         | ![WHIRLPOOL](./imgs/whirlpool_barycentric.png) | ![WHIRLPOOL](./imgs/whirlpool_barycentric_hue.png) |

## Bilinear Interpolate

    echo -n emcconville | vizsum -bilinear sumimg.png

| Digest  | Flag                                    | Hue only |
|---------|-----------------------------------------|----------|
| Adler32 | `-bilinear -adler32`                    | `-bilinear -adler32 -hue` |
|         | _same as `-hue`_                        | ![adler32](./imgs/adler32_bilinear_hue.png) |
| GOST    | `-bilinear -gost`                       | `-bilinear -gost -hue` |
|         | ![GOST](./imgs/gost_bilinear.png)       | ![GOST](./imgs/gost_bilinear_hue.png) |
| MD5     | `-bilinear -md5`                        | `-bilinear -md5 -hue` |
|         | ![MD5](./imgs/md5_bilinear.png)         | ![MD5](./imgs/md5_bilinear_hue.png) |
| SHA1    | `-bilinear -sha1`                       | `-bilinear -sha1 -hue` |
|         | ![SHA1](./imgs/sha1_bilinear.png)       | ![SHA1](./imgs/sha1_bilinear_hue.png) |
| WHIRLPOOL | `-bilinear -whirlpool`                | `-bilinear -whirlpool -hue` |
|         | ![WHIRLPOOL](./imgs/whirlpool_bilinear.png) | ![WHIRLPOOL](./imgs/whirlpool_bilinear_hue.png) |


## Inverse Interpolate

    echo -n emcconville | vizsum -inverse sumimg.png

| Digest  | Flag                                   | Hue only |
|---------|----------------------------------------|----------|
| Adler32 | `-inverse -adler32`                    | `-inverse -adler32 -hue` |
|         | _same as `-hue`_                       | ![adler32](./imgs/adler32_inverse_hue.png) |
| GOST    | `-inverse -gost`                       | `-inverse -gost -hue` |
|         | ![GOST](./imgs/gost_inverse.png)       | ![GOST](./imgs/gost_inverse_hue.png) |
| MD5     | `-inverse -md5`                        | `-inverse -md5 -hue` |
|         | ![MD5](./imgs/md5_inverse.png)         | ![MD5](./imgs/md5_inverse_hue.png) |
| SHA1    | `-inverse -sha1`                       | `-inverse -sha1 -hue` |
|         | ![SHA1](./imgs/sha1_inverse.png)       | ![SHA1](./imgs/sha1_inverse_hue.png) |
| WHIRLPOOL | `-inverse -whirlpool`                | `-inverse -whirlpool -hue` |
|         | ![WHIRLPOOL](./imgs/whirlpool_inverse.png) | ![WHIRLPOOL](./imgs/whirlpool_inverse_hue.png) |


## Shepards Interpolate

    echo -n emcconville | vizsum -shepards sumimg.png

| Digest  | Flag                                    | Hue only |
|---------|-----------------------------------------|----------|
| Adler32 | `-shepards -adler32`                    | `-shepards -adler32 -hue` |
|         | _same as `-hue`_                        | ![adler32](./imgs/adler32_shepards_hue.png) |
| GOST    | `-shepards -gost`                       | `-shepards -gost -hue` |
|         | ![GOST](./imgs/gost_shepards.png)       | ![GOST](./imgs/gost_shepards_hue.png) |
| MD5     | `-shepards -md5`                        | `-shepards -md5 -hue` |
|         | ![MD5](./imgs/md5_shepards.png)         | ![MD5](./imgs/md5_shepards_hue.png) |
| SHA1    | `-shepards -sha1`                       | `-shepards -sha1 -hue` |
|         | ![SHA1](./imgs/sha1_shepards.png)       | ![SHA1](./imgs/sha1_shepards_hue.png) |
| WHIRLPOOL | `-shepards -whirlpool`                | `-shepards -whirlpool -hue` |
|         | ![WHIRLPOOL](./imgs/whirlpool_shepards.png) | ![WHIRLPOOL](./imgs/whirlpool_shepards_hue.png) |


## Voronoi Interpolate

    echo -n emcconville | vizsum -voronoi sumimg.png

| Digest  | Flag                                   | Hue only |
|---------|----------------------------------------|----------|
| Adler32 | `-voronoi -adler32`                    | `-voronoi -adler32 -hue` |
|         | _same as `-hue`_                       | ![adler32](./imgs/adler32_voronoi_hue.png) |
| GOST    | `-voronoi -gost`                       | `-voronoi -gost -hue` |
|         | ![GOST](./imgs/gost_voronoi.png)       | ![GOST](./imgs/gost_voronoi_hue.png) |
| MD5     | `-voronoi -md5`                        | `-voronoi -md5 -hue` |
|         | ![MD5](./imgs/md5_voronoi.png)         | ![MD5](./imgs/md5_voronoi_hue.png) |
| SHA1    | `-voronoi -sha1`                       | `-voronoi -sha1 -hue` |
|         | ![SHA1](./imgs/sha1_voronoi.png)       | ![SHA1](./imgs/sha1_voronoi_hue.png) |
| WHIRLPOOL | `-voronoi -whirlpool`                | `-voronoi -whirlpool -hue` |
|         | ![WHIRLPOOL](./imgs/whirlpool_voronoi.png) | ![WHIRLPOOL](./imgs/whirlpool_voronoi_hue.png) |


# _&#64257;n_

Suggestions, comments, and requests are [welcome](https://github.com/emcconville/VizSum/issues).

