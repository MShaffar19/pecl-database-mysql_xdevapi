/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 2006-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Authors: Andrey Hristov <andrey@mysql.com>                           |
  +----------------------------------------------------------------------+
*/
#ifndef XMYSQLND_EXTENSION_PLUGIN_H
#define XMYSQLND_EXTENSION_PLUGIN_H

#include "ext/mysqlnd/mysqlnd_structs.h"

struct st_xmysqlnd_node_session;
struct st_xmysqlnd_node_session_data;
struct st_xmysqlnd_node_stmt;
struct st_xmysqlnd_node_stmt_result;
struct st_xmysqlnd_rowset_buffered;
struct st_xmysqlnd_rowset_fwd;
struct st_xmysqlnd_node_stmt_result_meta;
struct st_xmysqlnd_rowset;
struct st_xmysqlnd_protocol_frame_codec;

MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_object_factory);
MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_node_session);
MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_node_session_data);
MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_node_stmt);
MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_node_stmt_result);
MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_rowset_buffered);
MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_rowset_fwd);
MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_node_stmt_result_meta);
MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_rowset);
MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_protocol_packet_frame_codec);
MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_warning_list);

struct st_xmysqlnd_plugin__plugin_area_getters
{
	void ** (*get_node_session_area)(const struct st_xmysqlnd_node_session * conn, const unsigned int plugin_id);
	void ** (*get_node_session_data_data_area)(const struct st_xmysqlnd_node_session_data * conn, const unsigned int plugin_id);
	void ** (*get_node_stmt_area)(const struct st_xmysqlnd_node_stmt * stmt, unsigned int plugin_id);
	void ** (*get_node_stmt_result_area)(const struct st_xmysqlnd_node_stmt_result * result, unsigned int plugin_id);
	void ** (*get_rowset_buffered_area)(const struct st_xmysqlnd_rowset_buffered * result, unsigned int plugin_id);
	void ** (*get_rowset_fwd_area)(const struct st_xmysqlnd_rowset_fwd * result, unsigned int plugin_id);
	void ** (*get_node_query_result_meta_area)(const struct st_xmysqlnd_node_stmt_result_meta * result, unsigned int plugin_id);
	void ** (*get_rowset_area)(const struct st_xmysqlnd_rowset * result, unsigned int plugin_id);
	void ** (*get_pfc_area)(const struct st_xmysqlnd_protocol_frame_codec * pfc, unsigned int plugin_id);
};

extern struct st_xmysqlnd_plugin__plugin_area_getters xmysqlnd_plugin_area_getters;

#define xmysqlnd_plugin_get_node_session_plugin_area(s, p_id)				xmysqlnd_plugin_area_getters.get_node_session_area((s), (p_id))
#define xmysqlnd_plugin_get_node_session_data_plugin_area(s, p_id)			xmysqlnd_plugin_area_getters.get_node_session_data_data_area((s), (p_id))
#define xmysqlnd_plugin_get_node_stmt_plugin_area(s, p_id)					xmysqlnd_plugin_area_getters.get_node_stmt_area((s), (p_id))
#define xmysqlnd_plugin_get_node_stmt_result_plugin_area(r, p_id)			xmysqlnd_plugin_area_getters.get_node_stmt_result_area((r), (p_id))
#define xmysqlnd_plugin_get_rowset_buffered_plugin_area(r, p_id)	xmysqlnd_plugin_area_getters.get_rowset_buffered_area((r), (p_id))
#define xmysqlnd_plugin_get_rowset_fwd_plugin_area(r, p_id)		xmysqlnd_plugin_area_getters.get_rowset_fwd_area((r), (p_id))
#define xmysqlnd_plugin_get_node_query_result_meta_plugin_area(m, p_id)		xmysqlnd_plugin_area_getters.get_node_query_result_meta_area((m), (p_id))
#define xmysqlnd_plugin_get_rowset_plugin_area(r, p_id)						xmysqlnd_plugin_area_getters.get_rowset_area((r), (p_id))
#define xmysqlnd_plugin_get_pfc_plugin_area(pfc, p_id)						xmysqlnd_plugin_area_getters.get_pfc_area((pfc), (p_id))


struct st_xmysqlnd_plugin_methods_xetters
{
	struct st_xmnd_object_factory_xetters
	{
		MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_object_factory) * (*get)();
		void (*set)(MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_object_factory) *methods);
	} object_factory;

	struct st_xmnd_node_session_xetters
	{
		MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_node_session) * (*get)();
		void (*set)(MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_node_session) *methods);
	} node_session;

	struct st_xmnd_node_session_data_xetters
	{
		MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_node_session_data) * (*get)();
		void (*set)(MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_node_session_data) *methods);
	} node_session_data;

	struct st_xmnd_node_stmt_xetters
	{
		MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_node_stmt) * (*get)();
		void (*set)(MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_node_stmt) *methods);
	} node_stmt;

	struct st_xmnd_node_stmt_result_xetters
	{
		MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_node_stmt_result) * (*get)();
		void (*set)(MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_node_stmt_result) *methods);
	} node_stmt_result;

	struct st_xmnd_rowset_buffered_xetters
	{
		MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_rowset_buffered) * (*get)();
		void (*set)(MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_rowset_buffered) *methods);
	} rowset_buffered;

	struct st_xmnd_rowset_fwd_xetters
	{
		MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_rowset_fwd) * (*get)();
		void (*set)(MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_rowset_fwd) *methods);
	} rowset_fwd;

	struct st_xmnd_node_query_result_meta_xetters
	{
		MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_node_stmt_result_meta) * (*get)();
		void (*set)(MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_node_stmt_result_meta) *methods);
	} node_stmt_result_meta;

	struct st_xmnd_result_field_meta_xetters
	{
		MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_result_field_meta) * (*get)();
		void (*set)(MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_result_field_meta) *methods);
	} result_field_meta;

	struct st_xmnd_rowset_xetters
	{
		MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_rowset) * (*get)();
		void (*set)(MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_rowset) *methods);
	} rowset;

	struct st_xmnd_pfc_xetters
	{
		MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_protocol_packet_frame_codec) * (*get)();
		void (*set)(MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_protocol_packet_frame_codec) * methods);
	} pfc;

	struct st_xmnd_warning_list_xetters
	{
		MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_warning_list) * (*get)();
		void (*set)(MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_warning_list) * methods);
	} warning_list;

	struct st_xmnd_stmt_execution_state_xetters
	{
		MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_stmt_execution_state) * (*get)();
		void (*set)(MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_stmt_execution_state) * methods);
	} stmt_exec_state;
};

extern struct st_xmysqlnd_plugin_methods_xetters xmysqlnd_plugin_methods_xetters;


#define xmysqlnd_object_factory_get_methods()	xmysqlnd_plugin_methods_xetters.object_factory.get()
#define xmysqlnd_object_factory_set_methods(m)	xmysqlnd_plugin_methods_xetters.object_factory.set((m))

#define xmysqlnd_node_session_get_methods()			xmysqlnd_plugin_methods_xetters.node_session.get()
#define xmysqlnd_node_session_set_methods(m)		xmysqlnd_plugin_methods_xetters.node_session.set((m))

#define xmysqlnd_node_session_data_get_methods()	xmysqlnd_plugin_methods_xetters.node_session_data.get()
#define xmysqlnd_node_session_data_set_methods(m)	xmysqlnd_plugin_methods_xetters.node_session_data.set((m))

#define xmysqlnd_node_stmt_get_methods()				xmysqlnd_plugin_methods_xetters.node_stmt.get()
#define xmysqlnd_node_stmt_set_methods(m)				xmysqlnd_plugin_methods_xetters.node_stmt.set((m))

#define xmysqlnd_node_stmt_result_get_methods()			xmysqlnd_plugin_methods_xetters.node_stmt_result.get()
#define xmysqlnd_node_stmt_result_set_methods(m)		xmysqlnd_plugin_methods_xetters.node_stmt_result.set((m))

#define xmysqlnd_rowset_buffered_get_methods()			xmysqlnd_plugin_methods_xetters.rowset_buffered.get()
#define xmysqlnd_rowset_buffered_set_methods(m)			xmysqlnd_plugin_methods_xetters.rowset_buffered.set((m))

#define xmysqlnd_rowset_fwd_get_methods()				xmysqlnd_plugin_methods_xetters.rowset_fwd.get()
#define xmysqlnd_rowset_fwd_set_methods(m)				xmysqlnd_plugin_methods_xetters.rowset_fwd.set((m))

#define xmysqlnd_node_stmt_result_meta_get_methods()	xmysqlnd_plugin_methods_xetters.node_stmt_result_meta.get()
#define xmysqlnd_node_stmt_result_meta_set_methods(m)	xmysqlnd_plugin_methods_xetters.node_stmt_result_meta.set((m))

#define xmysqlnd_result_field_meta_get_methods()		xmysqlnd_plugin_methods_xetters.result_field_meta.get()
#define xmysqlnd_result_field_meta_set_methods(m)		xmysqlnd_plugin_methods_xetters.result_field_meta.set((m))

#define xmysqlnd_rowset_get_methods()					xmysqlnd_plugin_methods_xetters.rowset.get()
#define xmysqlnd_rowset_set_methods(m)					xmysqlnd_plugin_methods_xetters.rowset.set((m))

#define xmysqlnd_pfc_get_methods()						xmysqlnd_plugin_methods_xetters.pfc.get()
#define xmysqlnd_pfc_set_methods(m)						xmysqlnd_plugin_methods_xetters.pfc.set((m))

#define xmysqlnd_warning_list_get_methods()				xmysqlnd_plugin_methods_xetters.warning_list.get()
#define xmysqlnd_warning_list_set_methods(m)			xmysqlnd_plugin_methods_xetters.warning_list.set((m))

#define xmysqlnd_stmt_execution_state_get_methods()		xmysqlnd_plugin_methods_xetters.stmt_exec_state.get()
#define xmysqlnd_stmt_execution_state_set_methods(m)	xmysqlnd_plugin_methods_xetters.stmt_exec_state.set((m))

#endif	/* XMYSQLND_EXTENSION_PLUGIN_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
