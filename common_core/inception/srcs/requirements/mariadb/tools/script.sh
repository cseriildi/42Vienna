#!/bin/sh

if [ ! -d /var/lib/mysql/mysql ]; then
  mariadb-install-db --user=mysql --datadir=/var/lib/mysql --skip-test-db
fi

envsubst < /init.sql > /var/lib/mysql/init.sql
chmod +x /var/lib/mysql/init.sql

exec mariadbd --datadir='/var/lib/mysql'