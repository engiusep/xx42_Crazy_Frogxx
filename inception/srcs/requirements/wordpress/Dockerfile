# Dockerfile WordPress pour Inception

FROM debian:bookworm-slim

# Installer PHP + extensions et utilitaires
RUN apt update && apt install -y \
    php8.3-fpm \
    php8.3-mysql \
    php8.3-cli \
    php8.3-curl \
    php8.3-gd \
    php8.3-xml \
    php8.3-mbstring \
    wget \
    unzip \
    mariadb-client \
    && apt clean \
    && rm -rf /var/lib/apt/lists/*

# Créer le dossier WordPress
RUN mkdir -p /var/www/html

# Télécharger et décompresser WordPress
RUN wget https://wordpress.org/latest.tar.gz -O /tmp/wordpress.tar.gz \
    && tar -xzf /tmp/wordpress.tar.gz -C /var/www/html --strip-components=1 \
    && rm /tmp/wordpress.tar.gz

# Définir le dossier de travail
WORKDIR /var/www/html

# Exposer le port PHP-FPM
EXPOSE 9000

# Lancer PHP-FPM
CMD ["php-fpm8.3", "-F"
