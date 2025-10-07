FROM alpine:3.22.1

RUN apk update && apk add --no-cache \
  php83 php83-fpm php83-cli php83-phar php83-mbstring \
  php83-mysqli php83-json php83-curl php83-dom \
  php83-exif php83-fileinfo php83-iconv php83-openssl \
  php83-pdo php83-pdo_mysql php83-session php83-simplexml \
  php83-xml php83-xmlreader php83-xmlwriter php83-zip \
  mariadb-client \
  curl

COPY /conf/wordpress.conf /etc/php83/php-fpm.d/www.conf
COPY /conf/php.ini /etc/php83/conf.d/99-wordpress.ini
COPY tools/script.sh /script.sh
RUN chmod +x /script.sh

RUN curl -o /wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x /wp

WORKDIR /var/www/html

EXPOSE 9000

CMD ["/script.sh"]