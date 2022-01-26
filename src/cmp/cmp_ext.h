#ifndef CMP_EXT_H
#define CMP_EXT_H

#include "cmp/export.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

#define __CMP_ARRSIZE(x) (sizeof(x) / sizeof(x[0]))
#define __CMP_STRADDR(x) ((char const *)(char const(*)[__CMP_ARRSIZE(x)]){&(x)})

#ifdef __cplusplus
extern "C" {
#endif

struct cmp_ctx_s;

CMP_API bool cmp_read(struct cmp_ctx_s *, void *data, size_t limit);
CMP_API bool cmp_skip(struct cmp_ctx_s *, size_t count);
CMP_API size_t cmp_write(struct cmp_ctx_s *, const void *data, size_t count);

CMP_API int cmp_fseek(struct cmp_ctx_s *, int64_t offset, int whence);
CMP_API int64_t cmp_ftell(struct cmp_ctx_s *);

CMP_API void cmp_setup(struct cmp_ctx_s *ctx, FILE *fp);

CMP_API FILE *cmp_file(struct cmp_ctx_s *ctx);

/* Return a c-string.
 * data: a null-terminated string.
 * size: Maximum number of characters (not including the null one at the end)
 * to read. It will write back the resulting number of characters (again not
 * including the null one) read. */
CMP_API bool cmp_read_cstr(struct cmp_ctx_s *ctx, char *data, uint32_t *size);

#define CMP_WRITE_STR(ctx, msg) cmp_write_str(ctx, __CMP_STRADDR(msg), (uint32_t)(__CMP_ARRSIZE(msg) - 1))

CMP_API bool cmp_skip_str(struct cmp_ctx_s *ctx);

#ifdef __cplusplus
}
#endif

#endif
