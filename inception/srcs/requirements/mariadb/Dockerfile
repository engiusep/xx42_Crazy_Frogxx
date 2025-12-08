FROM debian:buster

# Sources pour Buster expirées
RUN sed -i 's|deb.debian.org|archive.debian.org|g' /etc/apt/sources.list && \
    sed -i 's|security.debian.org|archive.debian.org|g' /etc/apt/sources.list && \
    echo 'Acquire::Check-Valid-Until "false";' > /etc/apt/apt.conf.d/99no-check-valid-until

# Installer MariaDB + utilitaires manquants
RUN apt update && apt install -y mariadb-server mariadb-client procps

# Fix dossiers manquants
RUN mkdir -p /var/lib/mysql /var/run/mysqld && \
    chown -R mysql:mysql /var/lib/mysql /var/run/mysqld && \
    chmod 777 /var/run/mysqld

# Copier le script d'initialisation
COPY tools/script.sh /script.sh
RUN chmod +x /script.sh

ENTRYPOINT ["/script.sh"]
