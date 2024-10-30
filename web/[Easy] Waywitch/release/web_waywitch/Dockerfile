# Use the official Node.js image as a base
FROM node:alpine

RUN apk add --no-cache --update supervisor

WORKDIR /app

COPY src/ .
COPY config/supervisord.conf /etc/supervisord.conf
COPY --chown=root entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

RUN npm install express request mysql2
# Expose port 3000
EXPOSE 1337

COPY flag.txt /flag.txt

# Command to run the application
CMD ["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"]
