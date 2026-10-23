# Split from lab/docker-compose.yml service "php83-fpm"
# Base image pins the runtime version scanned for SCA (e.g. php2shell on affected PHP).
FROM php:8.3.35-fpm
