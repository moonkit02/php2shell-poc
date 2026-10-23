# Split from lab/docker-compose.yml service "nginx"
# Base image pins the runtime version scanned for SCA (e.g. php2shell on affected PHP).
FROM nginx:alpine
