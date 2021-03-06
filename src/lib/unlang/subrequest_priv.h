#pragma once
/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software Foundation,
 *  Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

/**
 * $Id$
 *
 * @file unlang/subrequest_priv.h
 *
 * @copyright 2019 The FreeRADIUS server project
 */
#ifdef __cplusplus
extern "C" {
#endif

#include <freeradius-devel/server/tmpl.h>
#include <freeradius-devel/util/dict.h>

typedef struct {
	tmpl_t			*vpt;

	tmpl_t			*src;
	tmpl_t			*dst;

	fr_dict_t const		*dict;
	fr_dict_attr_t const	*attr_packet_type;
	fr_dict_enum_t const	*type_enum;
} unlang_subrequest_kctx_t;

void	unlang_subrequest_free(REQUEST **child);

void unlang_subrequest_push(rlm_rcode_t *out, REQUEST *child,
			    unlang_subrequest_session_t const *session, bool top_frame);

int unlang_detached_child_init(REQUEST *request);

#ifdef __cplusplus
}
#endif
