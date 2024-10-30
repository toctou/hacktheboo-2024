#!/bin/sh
docker build --tag=el_mundo .
docker run -it -p 1337:1337 --rm --name=el_mundo el_mundo
