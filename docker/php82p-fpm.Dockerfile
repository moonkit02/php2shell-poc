# Split from lab/docker-compose.yml service "php82p-fpm"
# Base image pins the runtime version scanned for SCA (e.g. php2shell on affected PHP).
FROM php:8.2.35-fpm
