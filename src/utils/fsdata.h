/* vifm
 * Copyright (C) 2011 xaizek.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef VIFM__UTILS__FSDATA_H__
#define VIFM__UTILS__FSDATA_H__

/* Structure that maps arbitrary data onto file system tree.  Each node can
 * contain arbitrary amount of data, with size changed on every set operation.
 * No additional checks are performed in get/set functions. */

#include <stddef.h> /* size_t */

/* Declaration of opaque fsdata type. */
typedef struct fsdata_t fsdata_t;

/* prefix mode causes queries to return nearest match when exact match is not
 * available.  Returns NULL on error. */
fsdata_t * fsdata_create(int prefix);

/* Frees memory from the structure.  Freeing of NULL fsd is OK. */
void fsdata_free(fsdata_t *fsd);

/* Assigns (possibly with overwrite) data to specified path.  Returns zero on
 * success, otherwise non-zero is returned. */
int fsdata_set(fsdata_t *fsd, const char path[], const void *data, size_t len);

/* Retrieves data associated with the path (or closest predecessor on prefix
 * matches).  Doesn't change data content if path absent.  Returns zero on
 * success and non-zero on error. */
int fsdata_get(fsdata_t *fsd, const char path[], void *data, size_t len);

/* Invalidates all nodes from the root to the specified node if it exists.
 * Returns zero on success or non-zero if path wasn't found. */
int fsdata_invalidate(fsdata_t *fsd, const char path[]);

#endif /* VIFM__UTILS__FSDATA_H__ */

/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 noexpandtab cinoptions-=(0 : */
/* vim: set cinoptions+=t0 filetype=c : */
