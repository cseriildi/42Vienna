#!/bin/sh

if [ ! -f wp-config.php ]; then
    php83 /wp core download --allow-root

    php83 /wp config create \
      --dbname="$MYSQL_DATABASE" \
      --dbuser="$MYSQL_USER" \
      --dbpass="$MYSQL_PASSWORD" \
      --dbhost="mariadb" \
      --allow-root

    php83 /wp core install \
      --url="https://${DOMAIN_NAME}" \
      --title="$WORDPRESS_TITLE" \
      --admin_user="$WORDPRESS_ADMIN_USER" \
      --admin_password="$WORDPRESS_ADMIN_PASSWORD" \
      --admin_email="$WORDPRESS_ADMIN_EMAIL" \
      --allow-root

    php83 /wp user create $WORDPRESS_USER $WORDPRESS_USER_EMAIL \
      --role=author \
      --user_pass="$WORDPRESS_USER_PASSWORD" \
      --display_name="$WORDPRESS_USER" \
      --allow-root

    php83 /wp option update siteurl "https://${DOMAIN_NAME}" --allow-root
    php83 /wp option update home "https://${DOMAIN_NAME}" --allow-root

fi

exec php-fpm83 -F