DOMAIN = icseri.42.fr

all: open

prepare:
	sudo mkdir -p $$HOME/data/wordpress
	sudo mkdir -p $$HOME/data/mariadb

up: prepare
	docker compose -f srcs/docker-compose.yml up

build: prepare
	docker compose -f srcs/docker-compose.yml up --build -d

open: build
# 	curl -k https://$(DOMAIN);
	xdg-open https://$(DOMAIN) >/dev/null 2>&1 &

down:
	docker compose -f srcs/docker-compose.yml down

re: clean build

stop:
	docker compose -f srcs/docker-compose.yml stop

start:
	docker compose -f srcs/docker-compose.yml start

restart:
	docker compose -f srcs/docker-compose.yml restart

clean:
	[ -n "$$(docker ps -qa)" ] && docker stop $$(docker ps -qa) || true; \
	[ -n "$$(docker ps -qa)" ] && docker rm $$(docker ps -qa) || true; \
	[ -n "$$(docker images -qa)" ] && docker rmi -f $$(docker images -qa) || true; \
	[ -n "$$(docker volume ls -q)" ] && docker volume rm $$(docker volume ls -q) || true; \
	[ -n "$$(docker network ls -q)" ] && docker network rm $$(docker network ls -q) 2>/dev/null || true

deep-clean: clean
	sudo rm -rf $$HOME/data/wordpress/*
	sudo rm -rf $$HOME/data/mariadb/*

kill-443: clean
	sudo lsof -nP -iTCP:443 -sTCP:LISTEN | awk 'NR>1 {print $$2}' | xargs -r sudo kill -9

.PHONY: all prepare up build open down re stop start restart clean deep-clean kill-443
