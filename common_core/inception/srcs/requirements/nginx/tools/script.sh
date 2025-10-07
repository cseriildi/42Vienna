#!/bin/sh

mkdir -p ${CERTS}

if [ ! -f ${CERTS_CRT} ] || [ ! -f ${CERTS_KEY} ]; then
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -keyout "${CERTS_KEY}" \
        -out "${CERTS_CRT}" \
        -subj "/C=AT/ST=Vienna/L=Vienna/O=42Vienna/CN=${DOMAIN_NAME}"

    chmod 600 "${CERTS_KEY}"
    chmod 644 "${CERTS_CRT}"
fi

envsubst '$DOMAIN_NAME $CERTS_CRT $CERTS_KEY $PHP_HOST $PHP_PORT' < /nginx.conf > /etc/nginx/nginx.conf

nginx -g "daemon off;"