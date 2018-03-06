<?php
require_once(__DIR__."/../../connect.inc");
require_once(__DIR__."/../row_locking_utils.inc");

assert_mysql_xdevapi_loaded();

notify_worker_started();

$session = mysql_xdevapi\getSession($connection_uri);
$schema = $session->getSchema($test_schema_name);
$coll = $schema->getCollection($test_collection_name);

recv_let_worker_run_cmd();
// terminal/cmd 2
$session->startTransaction();
check_find_lock_one($coll, '1', 1, $Lock_none, MYSQLX_LOCK_DEFAULT);
// the execution should return immediately, no block should be present
notify_worker_ran_cmd();

recv_let_worker_rollback();
// terminal/cmd 2
check_find_lock_one($coll, '1', 1, $Lock_none, MYSQLX_LOCK_DEFAULT);
$session->rollback();
// rollback the open transaction
notify_worker_rolled_back();

recv_let_worker_end();
?>
