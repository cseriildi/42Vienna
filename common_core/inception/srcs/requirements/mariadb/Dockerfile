FROM alpine:3.22.1

RUN apk update && apk upgrade && apk add --no-cache \
    mariadb \
    mariadb-client \
    gettext

RUN mkdir -p /var/lib/mysql /var/log/mysql /run/mysqld
RUN chown -R mysql:mysql /var/lib/mysql /var/log/mysql /run/mysqld

COPY /conf/mariadb.conf /etc/my.cnf.d/mariadb-server.cnf
COPY tools/ /

RUN chmod +x /script.sh \
    && chown mysql:mysql /init.sql /script.sh

EXPOSE 3306

CMD ["/script.sh"]