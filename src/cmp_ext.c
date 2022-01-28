#include "cmp/cmp.h"
#include <assert.h>
#include <limits.h>
#include <string.h>

static_assert(sizeof(size_t) >= 8, "64-bits offset");
static_assert(sizeof(off_t) >= 8, "64-bits offset");

bool cmp_read(struct cmp_ctx_s *ctx, void *data, size_t limit)
{
    FILE *fp = (FILE *)ctx->buf;
    return fread(data, sizeof(uint8_t), limit, fp) == (limit * sizeof(uint8_t));
}

bool cmp_skip(struct cmp_ctx_s *ctx, size_t count)
{
    return fseeko((FILE *)ctx->buf, (off_t)count, SEEK_CUR) != -1;
}

size_t cmp_write(struct cmp_ctx_s *ctx, const void *data, size_t count)
{
    return fwrite(data, sizeof(uint8_t), count, (FILE *)ctx->buf);
}

int cmp_fseek(struct cmp_ctx_s *ctx, int64_t offset, int whence)
{
    return fseeko(cmp_file(ctx), (int64_t) offset, whence);
}

int64_t cmp_ftell(struct cmp_ctx_s *ctx)
{
    return (int64_t)ftello(cmp_file(ctx));
}

void cmp_setup(struct cmp_ctx_s *ctx, FILE *fp)
{
    cmp_init(ctx, fp, cmp_read, cmp_skip, cmp_write);
}

FILE *cmp_file(struct cmp_ctx_s *ctx) { return (FILE *)ctx->buf; }
