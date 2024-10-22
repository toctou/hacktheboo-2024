#!/bin/sh
docker build --tag=el_teteo .
docker run -it -p 1337:1337 --rm --name=el_teteo el_teteo
