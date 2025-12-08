FROM debian:buster

RUN sed -i 's|deb.debian.org|archive.debian.org|g' /etc/apt/sources.list && \
    sed -i 's|security.debian.org|archive.debian.org|g' /etc/apt/sources.list && \
    echo 'Acquire::Check-Valid-Until "false";' > /etc/apt/apt.conf.d/99no-check-valid-until && \
    apt-get update && \
    apt-get upgrade -y && \
    apt -y install wget && \
    apt install -y php7.3\
    php-fpm\
    php-mysql\
    mariadb-client

RUN sed -i 's|^listen = .*|listen = 9000|' /etc/php/7.3/fpm/pool.d/www.conf && \
    sed -i 's|^clear_env .*|clear_env = no|' /etc/php/7.3/fpm/pool.d/www.conf

RUN wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www

RUN cd /var/www && tar -xzf wordpress-6.0-fr_FR.tar.gz && rm wordpress-6.0-fr_FR.tar.gz

RUN		chown -R root:root /var/www/wordpress

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

RUN chmod +x wp-cli.phar

RUN mv wp-cli.phar /usr/local/bin/wp

COPY conf/auto_config.sh /auto_config.sh

RUN chmod +x auto_config.sh

ENTRYPOINT [ "/auto_config.sh" ]

RUN mkdir -p /run/php

CMD [ "/usr/sbin/php-fpm7.3 -F" ]

