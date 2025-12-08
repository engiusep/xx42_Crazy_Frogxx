#!/bin/bash

# Démarrage de MariaDB en arrière-plan
mysqld_safe &

# Attendre que MariaDB soit opérationnel
until mysqladmin ping >/dev/null 2>&1; do
  echo "Waiting for MariaDB to start..."
  sleep 2
done

# Configurer root avec mot de passe et créer base/utilisateur
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}'; FLUSH PRIVILEGES;"
mysql -uroot -p"${MYSQL_ROOT_PASSWORD}" -e "CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;"
mysql -uroot -p"${MYSQL_ROOT_PASSWORD}" -e "CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"
mysql -uroot -p"${MYSQL_ROOT_PASSWORD}" -e "GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%'; FLUSH PRIVILEGES;"

# Lancer MariaDB au premier plan
exec mysqld_safe
