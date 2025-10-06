#!/bin/sh

if [ ! -d /var/lib/mysql/mysql ]; then
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql

    mariadbd --skip-networking --user=mysql &
    pid="$!"

    until mariadb-admin ping --silent --socket=/run/mysqld/mysqld.sock; do
      sleep 1
    done

    echo "Creating database and users..."
    mariadb -u root --socket=/run/mysqld/mysqld.sock <<EOF
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
EOF

    kill "$pid"
    wait "$pid"
fi

exec mariadbd-safe --datadir='/var/lib/mysql'
