/*
 * Copyright (c) 2020, Circonus, Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above
 *      copyright notice, this list of conditions and the following
 *      disclaimer in the documentation and/or other materials provided
 *      with the distribution.
 *    * Neither the name Circonus, Inc. nor the names of its contributors
 *      may be used to endorse or promote products derived from this
 *      software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _UTILS_MTEV_LOGIC_H
#define _UTILS_MTEV_LOGIC_H

#include <mtev_defines.h>
#include <mtev_log.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mtev_logic_ast_t mtev_logic_ast_t;
typedef struct mtev_logic_exec_t mtev_logic_exec_t;
typedef struct mtev_logic_var_t mtev_logic_var_t;

typedef struct {
  mtev_boolean (*lookup)(void *context, const char *name, mtev_logic_var_t *outvar);
} mtev_logic_ops_t;

API_EXPORT(mtev_logic_ast_t *) mtev_logic_parse(const char *input, char **error);
API_EXPORT(void) mtev_logic_ast_free(mtev_logic_ast_t *);
API_EXPORT(mtev_logic_exec_t *) mtev_logic_exec_alloc(const mtev_logic_ops_t *);
API_EXPORT(void) mtev_logic_exec_free(mtev_logic_exec_t *);
API_EXPORT(mtev_boolean) mtev_logic_exec(mtev_logic_exec_t *, mtev_logic_ast_t *, void *);

API_EXPORT(mtev_boolean) mtev_logic_has_predicate(mtev_logic_ast_t *, const char *);

API_EXPORT(void) mtev_logic_var_set_string(mtev_logic_var_t *, const char *);
API_EXPORT(void) mtev_logic_var_set_stringn(mtev_logic_var_t *, const char *, size_t);
API_EXPORT(void) mtev_logic_var_set_string_copy(mtev_logic_var_t *, const char *);
API_EXPORT(void) mtev_logic_var_set_stringn_copy(mtev_logic_var_t *, const char *, size_t);
API_EXPORT(void) mtev_logic_var_set_int64(mtev_logic_var_t *, int64_t);
API_EXPORT(void) mtev_logic_var_set_double(mtev_logic_var_t *, double);

API_EXPORT(void) mtev_logic_ast_log(mtev_log_stream_t log, mtev_logic_ast_t *);

#ifdef __cplusplus
}
#endif

#endif
