#!/bin/sh

if [ ! -f wp-config.php ]; then
    php83 /wp core download --allow-root

    until mysql -h mariadb -u"$MYSQL_USER" -p"$MYSQL_PASSWORD" "$MYSQL_DATABASE" -e "SELECT 1;" > /dev/null 2>&1; do
        sleep 2
    done

    php83 /wp config create \
      --dbname="$MYSQL_DATABASE" \
      --dbuser="$MYSQL_USER" \
      --dbpass="$MYSQL_PASSWORD" \
      --dbhost="mariadb" \
      --allow-root

    php83 /wp core install \
      --url="$DOMAIN_NAME" \
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
fi

exec php-fpm83 -F