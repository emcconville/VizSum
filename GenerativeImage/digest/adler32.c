#include "adler32.h"

void ADLER32_Init(ADLER32_CTX* context)
{
    context->state = 1;
}
void ADLER32_Update(ADLER32_CTX* context, const uint8_t* data, const size_t len)
{
    uint32_t i, s[2];
    s[0] = context->state & 0xffff;
    s[1] = (context->state >> 16) & 0xffff;
    for (i = 0; i < (uint32_t)len; ++i) {
        s[0] += data[i];
        s[1] += s[0];
        if (s[1]>=0x7fffffff)
        {
            s[0] = s[0] % 0xfff1;
            s[1] = s[1] % 0xfff1;
        }
    }
    s[0] = s[0] % 0xfff1;
    s[1] = s[1] % 0xfff1;
    context->state = s[0] + (s[1] << 16);
}

void ADLER32_Final(ADLER32_CTX* context, uint8_t digest[ADLER32_DIGEST_SIZE])
{
    digest[0] = (unsigned char) ((context->state >> 24) & 0xff);
    digest[1] = (unsigned char) ((context->state >> 16) & 0xff);
    digest[2] = (unsigned char) ((context->state >> 8) & 0xff);
    digest[3] = (unsigned char) (context->state & 0xff);
    context->state = 0;
}
