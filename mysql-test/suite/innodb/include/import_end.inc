--copy_file $MYSQLD_DATADIR/test/t1.frm $MYSQLD_DATADIR/test/t2.frm
--copy_file $MYSQLD_DATADIR/test/t1.ibd $MYSQLD_DATADIR/test/t2.ibd
UNLOCK TABLES;
ALTER TABLE t2 IMPORT TABLESPACE;
--replace_regex $CREATE_OPTIONS_REGEX
SHOW CREATE TABLE t2;
SELECT * FROM t2;
DROP TABLE t1, t2;