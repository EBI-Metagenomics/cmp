#ifndef CMP_EXT_H
#define CMP_EXT_H

#include "cmp/export.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct cmp_ctx_s;

CMP_API bool    cmp_read(struct cmp_ctx_s *, void *data, size_t limit);
CMP_API bool    cmp_skip(struct cmp_ctx_s *, size_t count);
CMP_API size_t  cmp_write(struct cmp_ctx_s *, const void *data, size_t count);
CMP_API int     cmp_fseek(struct cmp_ctx_s *, int64_t offset, int whence);
CMP_API int64_t cmp_ftell(struct cmp_ctx_s *);

CMP_API void cmp_setup(struct cmp_ctx_s *ctx, FILE *fp);

CMP_API FILE *cmp_file(struct cmp_ctx_s *ctx);

#ifdef __cplusplus
}
#endif

#endif
