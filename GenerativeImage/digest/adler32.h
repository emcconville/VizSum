#ifndef __VizSum__adler32__
#define __VizSum__adler32__

#include <stdint.h>
#include <stddef.h>

typedef struct {
    uint32_t state;
} ADLER32_CTX;

#define ADLER32_DIGEST_SIZE 4

void ADLER32_Init(ADLER32_CTX* context);
void ADLER32_Update(ADLER32_CTX* context, const uint8_t* data, const size_t len);
void ADLER32_Final(ADLER32_CTX* context, uint8_t digest[ADLER32_DIGEST_SIZE]);

#endif /* defined(__VizSum__adler32__) */
