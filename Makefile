CC := clang
CFLAGS := $(shell MagickWand-config --cflags)
LDFLAGS := $(shell MagickWand-config --ldflags)
PREFIX := /usr/local
SOURCES=GenerativeImage/algos/algos_adler32.c \
        GenerativeImage/algos/algos_gost.c \
        GenerativeImage/algos/algos_md5.c \
        GenerativeImage/algos/algos_sha1.c \
        GenerativeImage/algos/algos_whirlpool.c \
        GenerativeImage/algos.c \
        GenerativeImage/digest/adler32.c \
        GenerativeImage/digest/gost.c \
        GenerativeImage/digest/md5.c \
        GenerativeImage/digest/sha1.c \
        GenerativeImage/digest/whirlpool.c \
        GenerativeImage/hashimg.c \
        GenerativeImage/vizsum.c

vizsum:
	${CC} -o vizsum ${CFLAGS} ${LDFLAGS} -I./GenerativeImage/digest -I./GenerativeImage/algos -I./GenerativeImage ${SOURCES}

install: vizsum
	install -m 755 vizsum ${PREFIX}/bin

uninstall:
	rm -f ${PREFIX}/bin/vizsum

clean:
	rm -f vizsum

all: vizsum