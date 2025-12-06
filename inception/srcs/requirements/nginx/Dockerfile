FROM debian:bookworm

RUN apt update && \
    apt install nginx -y && \
    apt install vim -y && \
    apt install curl -y && \
    mkdir -p /etc/nginx/ssl && \
    apt install openssl -y && \
    openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=login.42.fr/UID=login" && \
    mkdir -p /var/run/nginx && \
    apt clean

RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html 

COPY conf/nginx.conf  /etc/nginx/sites-available/default

CMD [ "nginx", "-g", "daemon off;" ]