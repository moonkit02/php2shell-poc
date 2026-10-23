# Split from lab/docker-compose.yml service "php56-fpm"
# Base image pins the runtime version scanned for SCA (e.g. php2shell on affected PHP).
FROM php:5.6.40-fpm
