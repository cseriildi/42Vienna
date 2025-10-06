FROM alpine:3.22.1

RUN apk update && apk upgrade && apk add --no-cache nginx openssl

COPY conf/nginx.conf /etc/nginx/nginx.conf

COPY tools/script.sh /script.sh

RUN chmod +x /script.sh

EXPOSE		80 443

CMD ["/script.sh"]
