# Split from lab/docker-compose.yml service "apache56"
# Base image pins the runtime version scanned for SCA (e.g. php2shell on affected PHP).
FROM php:5.6.40-apache
