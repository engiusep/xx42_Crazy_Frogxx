FROM debian:12

RUN apt update && apt upgrade && apt install -y \
    nginx

CMD [ "nginx","-g", "daemon off;" ]