#include "cmp/cmp.h"
#include <assert.h>
#include <limits.h>

bool cmp_read(struct cmp_ctx_s *ctx, void *data, size_t limit)
{
    FILE *fp = (FILE *)ctx->buf;
    return fread(data, sizeof(uint8_t), limit, fp) == (limit * sizeof(uint8_t));
}

bool cmp_skip(struct cmp_ctx_s *ctx, size_t count)
{
    assert(count <= ULONG_MAX);
    return fseek((FILE *)ctx->buf, (long)count, SEEK_CUR);
}

size_t cmp_write(struct cmp_ctx_s *ctx, const void *data, size_t count)
{
    return fwrite(data, sizeof(uint8_t), count, (FILE *)ctx->buf);
}

void cmp_setup(struct cmp_ctx_s *ctx, FILE *fp)
{
    cmp_init(ctx, fp, cmp_read, cmp_skip, cmp_write);
}

FILE *cmp_file(struct cmp_ctx_s *ctx) { return (FILE *)ctx->buf; }

bool cmp_read_str(cmp_ctx_t *ctx, char *data, uint32_t *size)
{
    bool r = __cmp_read_str(ctx, data, size);
    assert(*size > 0);
    *size += 1;
    return r;
}
