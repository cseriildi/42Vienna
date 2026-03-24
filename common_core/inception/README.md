# About the Inception project

## Summary

This project aims to broaden your knowledge of system administration by using Docker. You will virtualize several Docker images, creating them in your new personal virtual machine. The goal is to set up a small infrastructure composed of different services using `docker-compose`.

## Mandatory Part

- Set up a small infrastructure with:
  - A Docker container with **NGINX** and TLSv1.2 or TLSv1.3.
  - A Docker container with **WordPress** and `php-fpm`.
  - A Docker container with **MariaDB**.
- Use `docker-compose.yml` to manage the containers.
- Each service must have its own `Dockerfile`.
- Use a volume for the WordPress database and another for the WordPress files.
- All containers must be connected through a Docker network.
- The server must be accessible at `https://<your_login>.42.fr`.
