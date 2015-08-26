# vizsum

A generative image exercise for converting checksum data visual data.
ImageMagick's sparse-color interpolation methods are used to create unique images.

## Barycentric Interpolate (default)

    echo -n emcconville | vizsum -barycentric sumimg.png

Adler32 _-adler32_

![adler32](./imgs/adler32_barycentric.png)

GOST _-gost_

![GOST](./imgs/gost_barycentric.png)

MD5 _-md5_ (default)

![MD5](./imgs/md5_barycentric.png)

SHA1 _-sha1_

![SHA1](./imgs/sha1_barycentric.png)

WHIRLPOOL _-whirlpool_

![WHIRLPOOL](./imgs/whirlpool_barycentric.png)

### Hue only

    echo -n emcconville | vizsum -barycentric -hue sumimg.png

Adler32 _-adler32_

![adler32](./imgs/adler32_barycentric_hue.png)

GOST _-gost_

![GOST](./imgs/gost_barycentric_hue.png)

MD5 _-md5_ (default)

![MD5](./imgs/md5_barycentric_hue.png)

SHA1 _-sha1_

![SHA1](./imgs/sha1_barycentric_hue.png)

WHIRLPOOL _-whirlpool_

![WHIRLPOOL](./imgs/whirlpool_barycentric_hue.png)

## Bilinear Interpolate

    echo -n emcconville | vizsum -bilinear sumimg.png

Adler32 _-adler32_

![adler32](./imgs/adler32_bilinear.png)

GOST _-gost_

![GOST](./imgs/gost_bilinear.png)

MD5 _-md5_ (default)

![MD5](./imgs/md5_bilinear.png)

SHA1 _-sha1_

![SHA1](./imgs/sha1_bilinear.png)

WHIRLPOOL _-whirlpool_

![WHIRLPOOL](./imgs/whirlpool_bilinear.png)

### Hue only

    echo -n emcconville | vizsum -bilinear -hue sumimg.png

Adler32 _-adler32_

![adler32](./imgs/adler32_bilinear_hue.png)

GOST _-gost_

![GOST](./imgs/gost_bilinear_hue.png)

MD5 _-md5_ (default)

![MD5](./imgs/md5_bilinear_hue.png)

SHA1 _-sha1_

![SHA1](./imgs/sha1_bilinear_hue.png)

WHIRLPOOL _-whirlpool_

![WHIRLPOOL](./imgs/whirlpool_bilinear_hue.png)

## Inverse Interpolate

    echo -n emcconville | vizsum -inverse sumimg.png

Adler32 _-adler32_

![adler32](./imgs/adler32_inverse.png)

GOST _-gost_

![GOST](./imgs/gost_inverse.png)

MD5 _-md5_ (default)

![MD5](./imgs/md5_inverse.png)

SHA1 _-sha1_

![SHA1](./imgs/sha1_inverse.png)

WHIRLPOOL _-whirlpool_

![WHIRLPOOL](./imgs/whirlpool_inverse.png)

### Hue only

    echo -n emcconville | vizsum -inverse -hue sumimg.png

Adler32 _-adler32_

![adler32](./imgs/adler32_inverse_hue.png)

GOST _-gost_

![GOST](./imgs/gost_inverse_hue.png)

MD5 _-md5_ (default)

![MD5](./imgs/md5_inverse_hue.png)

SHA1 _-sha1_

![SHA1](./imgs/sha1_inverse_hue.png)

WHIRLPOOL _-whirlpool_

![WHIRLPOOL](./imgs/whirlpool_inverse_hue.png)

## Shepards Interpolate

    echo -n emcconville | vizsum -shepards sumimg.png

Adler32 _-adler32_

![adler32](./imgs/adler32_shepards.png)

GOST _-gost_

![GOST](./imgs/gost_shepards.png)

MD5 _-md5_ (default)

![MD5](./imgs/md5_shepards.png)

SHA1 _-sha1_

![SHA1](./imgs/sha1_shepards.png)

WHIRLPOOL _-whirlpool_

![WHIRLPOOL](./imgs/whirlpool_shepards.png)

### Hue only

    echo -n emcconville | vizsum -shepards -hue sumimg.png

Adler32 _-adler32_

![adler32](./imgs/adler32_shepards_hue.png)

GOST _-gost_

![GOST](./imgs/gost_shepards_hue.png)

MD5 _-md5_ (default)

![MD5](./imgs/md5_shepards_hue.png)

SHA1 _-sha1_

![SHA1](./imgs/sha1_shepards_hue.png)

WHIRLPOOL _-whirlpool_

![WHIRLPOOL](./imgs/whirlpool_shepards_hue.png)

## Voronoi Interpolate

    echo -n emcconville | vizsum -voronoi sumimg.png

Adler32 _-adler32_

![adler32](./imgs/adler32_voronoi.png)

GOST _-gost_

![GOST](./imgs/gost_voronoi.png)

MD5 _-md5_ (default)

![MD5](./imgs/md5_voronoi.png)

SHA1 _-sha1_

![SHA1](./imgs/sha1_voronoi.png)

WHIRLPOOL _-whirlpool_

![WHIRLPOOL](./imgs/whirlpool_voronoi.png)

### Hue only

    echo -n emcconville | vizsum -voronoi -hue sumimg.png

Adler32 _-adler32_

![adler32](./imgs/adler32_voronoi_hue.png)

GOST _-gost_

![GOST](./imgs/gost_voronoi_hue.png)

MD5 _-md5_ (default)

![MD5](./imgs/md5_voronoi_hue.png)

SHA1 _-sha1_

![SHA1](./imgs/sha1_voronoi_hue.png)

WHIRLPOOL _-whirlpool_

![WHIRLPOOL](./imgs/whirlpool_voronoi_hue.png)

# _&#64257;n_

Suggestions, comments, and request are [welcome](https://github.com/emcconville/VizSum/issues).

