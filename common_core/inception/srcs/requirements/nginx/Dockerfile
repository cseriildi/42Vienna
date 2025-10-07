FROM alpine:3.22.1

RUN apk update && apk upgrade && apk add --no-cache \
    nginx \
    openssl \
    gettext

COPY conf/nginx.conf /nginx.conf
COPY tools/script.sh /script.sh

RUN chmod +x /script.sh

EXPOSE 443

CMD ["/script.sh"]
