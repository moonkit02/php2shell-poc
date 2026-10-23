# Realistic pattern: GENERIC base image, PHP installed in the build steps.
# The runtime version lives in the RUN layer below, NOT in FROM. Parsing FROM
# here yields only "debian" -- it reveals nothing about PHP. The php version is
# only knowable by BUILDING this image and scanning the result.
FROM debian:bookworm-slim
RUN apt-get update \
 && apt-get install -y --no-install-recommends ca-certificates curl lsb-release gnupg \
 && curl -sSLo /tmp/sury.deb https://packages.sury.org/debsuryorg-archive-keyring.deb \
 && dpkg -i /tmp/sury.deb \
 && echo "deb [signed-by=/usr/share/keyrings/deb.sury.org-php.gpg] https://packages.sury.org/php/ $(. /etc/os-release && echo $VERSION_CODENAME) main" > /etc/apt/sources.list.d/php.list \
 && apt-get update \
 && apt-get install -y --no-install-recommends apache2 libapache2-mod-php5.6 php5.6-cli \
 && rm -rf /var/lib/apt/lists/*
# To reproduce php2shell, pin an affected patch, e.g.:  php5.6-cli=5.6.34-1+...
# (the default installs sury's CURRENT build, which is already patched >= fix version).
