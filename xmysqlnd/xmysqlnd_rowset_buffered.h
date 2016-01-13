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

#ifndef XMYSQLND_ROWSET_BUFFERED_H
#define XMYSQLND_ROWSET_BUFFERED_H

#include "xmysqlnd_driver.h"

struct st_xmysqlnd_node_stmt;
struct st_xmysqlnd_node_stmt_result_meta;

#ifdef __cplusplus
extern "C" {
#endif

typedef struct st_xmysqlnd_rowset_buffered XMYSQLND_ROWSET_BUFFERED;


typedef enum_func_status	(*func_xmysqlnd_rowset_buffered__init)(XMYSQLND_ROWSET_BUFFERED * const result, MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_object_factory) *factory, struct st_xmysqlnd_node_stmt * const stmt, MYSQLND_STATS * const stats, MYSQLND_ERROR_INFO * const error_info);
typedef enum_func_status	(*func_xmysqlnd_rowset_buffered__next)(XMYSQLND_ROWSET_BUFFERED * const result, MYSQLND_STATS * const stats, MYSQLND_ERROR_INFO * const error_info);
typedef enum_func_status	(*func_xmysqlnd_rowset_buffered__fetch_current)(XMYSQLND_ROWSET_BUFFERED * const result, zval * row, MYSQLND_STATS * const stats, MYSQLND_ERROR_INFO * const error_info);
typedef enum_func_status	(*func_xmysqlnd_rowset_buffered__fetch_one)(XMYSQLND_ROWSET_BUFFERED * const result, const size_t row_cursor, zval * row, MYSQLND_STATS * const stats, MYSQLND_ERROR_INFO * const error_info);
typedef enum_func_status	(*func_xmysqlnd_rowset_buffered__fetch_all)(XMYSQLND_ROWSET_BUFFERED * const result, zval * set, MYSQLND_STATS * const stats, MYSQLND_ERROR_INFO * const error_info);
typedef enum_func_status	(*func_xmysqlnd_rowset_buffered__rewind)(XMYSQLND_ROWSET_BUFFERED * const result);
typedef zend_bool			(*func_xmysqlnd_rowset_buffered__eof)(const XMYSQLND_ROWSET_BUFFERED * const result);

typedef zval *				(*func_xmysqlnd_rowset_buffered__create_row)(XMYSQLND_ROWSET_BUFFERED * const result, const struct st_xmysqlnd_node_stmt_result_meta * const meta, MYSQLND_STATS * const stats, MYSQLND_ERROR_INFO * const error_info);
typedef void				(*func_xmysqlnd_rowset_buffered__destroy_row)(XMYSQLND_ROWSET_BUFFERED * const result, zval * row, MYSQLND_STATS * const stats, MYSQLND_ERROR_INFO * const error_info);
typedef enum_func_status	(*func_xmysqlnd_rowset_buffered__add_row)(XMYSQLND_ROWSET_BUFFERED * const result, zval * row, MYSQLND_STATS * const stats, MYSQLND_ERROR_INFO * const error_info);
typedef size_t				(*func_xmysqlnd_rowset_buffered__get_row_count)(const XMYSQLND_ROWSET_BUFFERED * const result);
typedef void				(*func_xmysqlnd_rowset_buffered__free_rows_contents)(XMYSQLND_ROWSET_BUFFERED * const result, MYSQLND_STATS * const stats, MYSQLND_ERROR_INFO * const error_info);
typedef void				(*func_xmysqlnd_rowset_buffered__free_rows)(XMYSQLND_ROWSET_BUFFERED * const result, MYSQLND_STATS * const stats, MYSQLND_ERROR_INFO * const error_info);

typedef enum_func_status	(*func_xmysqlnd_rowset_buffered__attach_meta)(XMYSQLND_ROWSET_BUFFERED * const result, struct st_xmysqlnd_node_stmt_result_meta * const meta, MYSQLND_STATS * const stats, MYSQLND_ERROR_INFO * const error_info);

typedef void				(*func_xmysqlnd_rowset_buffered__free_contents)(XMYSQLND_ROWSET_BUFFERED * const result, MYSQLND_STATS * const stats, MYSQLND_ERROR_INFO * const error_info);
typedef void				(*func_xmysqlnd_rowset_buffered__dtor)(XMYSQLND_ROWSET_BUFFERED * const result, MYSQLND_STATS * stats, MYSQLND_ERROR_INFO * error_info);

MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_rowset_buffered)
{
	func_xmysqlnd_rowset_buffered__init init;

	func_xmysqlnd_rowset_buffered__next next;
	func_xmysqlnd_rowset_buffered__fetch_current fetch_current;
	func_xmysqlnd_rowset_buffered__fetch_one fetch_one;
	func_xmysqlnd_rowset_buffered__fetch_all fetch_all;
	func_xmysqlnd_rowset_buffered__rewind rewind;
	func_xmysqlnd_rowset_buffered__eof eof;

	func_xmysqlnd_rowset_buffered__create_row create_row;
	func_xmysqlnd_rowset_buffered__destroy_row destroy_row;
	func_xmysqlnd_rowset_buffered__add_row add_row;
	func_xmysqlnd_rowset_buffered__get_row_count get_row_count;
	func_xmysqlnd_rowset_buffered__free_rows_contents free_rows_contents;
	func_xmysqlnd_rowset_buffered__free_rows free_rows;

	func_xmysqlnd_rowset_buffered__attach_meta attach_meta;

	func_xmysqlnd_rowset_buffered__free_contents free_contents;
	func_xmysqlnd_rowset_buffered__dtor dtor;
};


struct st_xmysqlnd_rowset_buffered
{
	struct st_xmysqlnd_node_stmt * stmt;
	struct st_xmysqlnd_node_stmt_result_meta * meta;

	zval ** rows; /* every row is a memory segment of field_count * sizeof(zval) */
	size_t row_count;
	size_t rows_allocated;
	size_t row_cursor;

	MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_rowset_buffered) m;
	zend_bool		persistent;
};

PHPAPI extern MYSQLND_CLASS_METHOD_TABLE_NAME_FORWARD(xmysqlnd_rowset_buffered);

PHPAPI XMYSQLND_ROWSET_BUFFERED * xmysqlnd_rowset_buffered_init(struct st_xmysqlnd_node_stmt * stmt, const zend_bool persistent, MYSQLND_CLASS_METHODS_TYPE(xmysqlnd_object_factory) *object_factory,  MYSQLND_STATS * stats, MYSQLND_ERROR_INFO * error_info);
PHPAPI void xmysqlnd_rowset_buffered_free(XMYSQLND_ROWSET_BUFFERED * const result, MYSQLND_STATS * stats, MYSQLND_ERROR_INFO * error_info);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* XMYSQLND_ROWSET_BUFFERED_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
