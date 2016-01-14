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
#include "php.h"
#include "ext/mysqlnd/mysqlnd.h"
#include "ext/mysqlnd/mysqlnd_statistics.h"
#include "ext/mysqlnd/mysqlnd_debug.h"
#include "xmysqlnd.h"
#include "xmysqlnd_driver.h"
#include "xmysqlnd_node_session.h"

static zend_bool xmysqlnd_library_initted = FALSE;

static struct st_mysqlnd_plugin_core xmysqlnd_plugin_core =
{
	{
		MYSQLND_PLUGIN_API_VERSION,
		"xmysqlnd",
		XMYSQLND_VERSION_ID,
		PHP_XMYSQLND_VERSION,
		"PHP License 3.01",
		"Andrey Hristov <andrey@mysql.com>",
		{
			NULL, /* will be filled later */
			mysqlnd_stats_values_names,
		},
		{
			NULL /* plugin shutdown */
		}
	}
};


/* {{{ mysqlnd_library_end */
PHPAPI void xmysqlnd_library_end(void)
{
	if (xmysqlnd_library_initted == TRUE) {
		mysqlnd_stats_end(xmysqlnd_global_stats, 1);
		xmysqlnd_global_stats = NULL;
		xmysqlnd_library_initted = FALSE;
	}
}
/* }}} */


/* {{{ mysqlnd_library_init */
PHPAPI void xmysqlnd_library_init(void)
{
	if (xmysqlnd_library_initted == FALSE) {
		xmysqlnd_library_initted = TRUE;

		/* Should be calloc, as mnd_calloc will reference LOCK_access*/
		mysqlnd_stats_init(&xmysqlnd_global_stats, XMYSQLND_STAT_LAST, 1);
		{
			xmysqlnd_plugin_core.plugin_header.plugin_stats.values = xmysqlnd_global_stats;
			mysqlnd_plugin_register_ex((struct st_mysqlnd_plugin_header *) &xmysqlnd_plugin_core);
		}
	}
}
/* }}} */

/* {{{ xmysqlnd_get_client_info */
PHPAPI const char * xmysqlnd_get_client_info()
{
	return PHP_XMYSQLND_VERSION;
}
/* }}} */


/* {{{ xmysqlnd_get_client_version */
PHPAPI unsigned int xmysqlnd_get_client_version()
{
	return XMYSQLND_VERSION_ID;
}
/* }}} */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
