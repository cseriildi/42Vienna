#!/bin/sh

mkdir -p /etc/nginx/ssl

if [ ! -f /etc/nginx/ssl/localhost.crt ] || [ ! -f /etc/nginx/ssl/localhost.key ]; then
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -keyout /etc/nginx/ssl/localhost.key \
        -out /etc/nginx/ssl/localhost.crt \
        -subj "/C=AT/ST=Vienna/L=Vienna/O=42Vienna/OU=Student/CN=localhost"
fi

chmod 600 /etc/nginx/ssl/localhost.key
chmod 644 /etc/nginx/ssl/localhost.crt

nginx -g "daemon off;"
