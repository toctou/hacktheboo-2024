#!/bin/sh
docker build --tag=el_pipo .
docker run -it -p 1337:1337 --rm --name=el_pipo el_pipo
