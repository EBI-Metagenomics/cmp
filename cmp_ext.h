#ifndef CMP_EXT_H
#define CMP_EXT_H

#include "cmp.h"
#include <stdbool.h>
#include <stdio.h>

struct cmp_ctx_s;

bool cmp_read(struct cmp_ctx_s *, void *data, size_t limit);
bool cmp_skip(struct cmp_ctx_s *, size_t count);
size_t cmp_write(struct cmp_ctx_s *, const void *data, size_t count);

void cmp_setup(struct cmp_ctx_s *ctx, FILE *fp);

FILE *cmp_file(struct cmp_ctx_s *ctx);

/* Return a c-string.
 * data: a null-terminated string.
 * size: number of characters including the null at the end.  */
bool cmp_read_str(cmp_ctx_t *ctx, char *data, uint32_t *size);

#endif
