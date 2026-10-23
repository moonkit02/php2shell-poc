# Split from lab/docker-compose.yml service "php74-fpm"
# Base image pins the runtime version scanned for SCA (e.g. php2shell on affected PHP).
FROM php:7.4.33-fpm
